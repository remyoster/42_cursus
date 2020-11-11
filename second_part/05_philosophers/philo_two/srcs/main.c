/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 08:20:12 by roster            #+#    #+#             */
/*   Updated: 2020/10/09 10:50:30 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"
#include <stdlib.h>

/*
** Loop through each philosopher and check death condition
** (last_time_eat > argv2). If a philo died, it prints it and stop monitoring.
** If there is a victory_nb it also check if this number is reached and stop
** the simulation if it is
*/

static void	monitor(t_philo *philo, t_data *data)
{
	size_t idx;

	while (1)
	{
		idx = 0;
		while (idx < data->nb_philo)
		{
			sem_wait(philo[idx].sem);
			if (get_time() - philo[idx].last_time_eat > data->time_to_die)
			{
				print_end(&philo[idx], DIED);
				sem_post(philo[idx].sem);
				return ;
			}
			sem_post(philo[idx].sem);
			if (data->victory_nb > 0 && data->satieted_philo == data->nb_philo)
			{
				print_end(&philo[idx], FULL);
				return ;
			}
			idx++;
		}
		ft_usleep(1000);
	}
}

/*
** Loop on each philo struct to close and unlink their semaphores, and free its
** name. Then it close wirte and forks semaphores and free philosophers
*/

static void	clean_prog(t_philo *philo, t_data data, int err)
{
	size_t idx;

	if (err != 0)
		print_error(err);
	idx = 0;
	while (idx < data.nb_philo)
	{
		sem_close(philo[idx].sem);
		sem_close(philo[idx].sem_fork);
		sem_unlink(philo[idx].name);
		free(philo[idx].name);
		idx++;
	}
	sem_close(data.write_lock);
	sem_unlink("/write");
	sem_unlink("/forks");
	free(philo);
}

/*
** Call parser to check entries and initialize data struc. Then malloc
** philosophers and initialize them with init. Once each philosopher
** is created, it runs the monitor to check the death timing. pthread_join
** wait for all thread to finish (with the condition philo_die). At the end
** it calls clean_prog to free and destroy.
*/

int			main(int ac, char **av)
{
	int		err;
	int		idx;
	t_data	data;
	t_philo	*philo;

	if ((err = parser(ac, av, &data)) != 0)
		return (print_error(err));
	else
	{
		if (!(philo = (t_philo *)malloc(sizeof(t_philo) * data.nb_philo)))
			return (print_error(MALLOC));
		philo = memset(philo, 0, sizeof(t_philo) * data.nb_philo);
		if ((err = init(&philo, &data)) == 0)
			monitor(philo, &data);
		idx = -1;
		while (++idx < (int)data.nb_philo)
			pthread_join(philo[idx].thread_id, NULL);
		clean_prog(philo, data, err);
	}
	return (0);
}
