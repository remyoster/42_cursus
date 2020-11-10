/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 08:20:12 by roster            #+#    #+#             */
/*   Updated: 2020/10/08 09:31:32 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
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
			pthread_mutex_lock(&philo[idx].mutex);
			if (get_time() - philo[idx].last_time_eat > data->time_to_die)
			{
				print_end(&philo[idx], DIED);
				pthread_mutex_unlock(&philo[idx].mutex);
				return ;
			}
			pthread_mutex_unlock(&philo[idx].mutex);
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
** Loop on each philo struct to destroy their mutexs. Then it free all
** philosophers and forks
*/

static void	clean_prog(t_philo *philo, t_fork *forks, t_data data, int err)
{
	size_t idx;

	if (err != 0)
		print_error(err);
	idx = 0;
	while (idx < data.nb_philo)
	{
		pthread_mutex_destroy(&forks[idx].mutex);
		pthread_mutex_destroy(&philo[idx].mutex);
		idx++;
	}
	pthread_mutex_destroy(&data.write_lock);
	free(philo);
	free(forks);
}

/*
** Call parser to check entries and initialize data struc. Then malloc
** philosophers and forks and initialize them with init. Once each philosopher
** is created, it runs the monitor to check the death timing. pthread_join
** wait for all thread to finish (with the condition philo_die). At the end
** it calls clean_prog to free and destroy.
*/

int			main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;
	t_fork	*forks;
	int		err;
	int		idx;

	if ((err = parser(ac, av, &data)) != 0)
		return (print_error(err));
	else
	{
		if (!(forks = (t_fork *)malloc(sizeof(t_fork) * data.nb_philo))
			|| !(philo = (t_philo *)malloc(sizeof(t_philo) * data.nb_philo)))
			return (print_error(MALLOC));
		philo = memset(philo, 0, sizeof(t_philo) * data.nb_philo);
		idx = -1;
		if ((err = init(&philo, &forks, &data)) == 0)
			monitor(philo, &data);
		data.philo_died = true;
		while (++idx < (int)data.nb_philo)
			pthread_join(philo[idx].thread_id, NULL);
		clean_prog(philo, forks, data, err);
	}
	return (0);
}
