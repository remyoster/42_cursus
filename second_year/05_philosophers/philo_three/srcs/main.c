/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 08:20:12 by roster            #+#    #+#             */
/*   Updated: 2020/10/08 11:09:33 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
** Loop on the philosopher last_time_eat each ms to check death condition. It
** death is reached, it unlocks the death semaphore and print his death
*/

void		monitor(t_philo *philo, t_data *data)
{
	while (1)
	{
		sem_wait(philo->sem);
		if (get_time() - philo->last_time_eat > data->time_to_die)
		{
			print_end(philo, data, DIED);
			sem_post(philo->data->sem_died);
			return ;
		}
		sem_post(philo->sem);
		ft_usleep(1000);
	}
}

/*
** It each philosopher if satieted the loop will finish and if nobody dies it
** will end up the simulation
*/

static void	*satieted_monitor(void *arg)
{
	t_data	*data;
	size_t	idx;

	data = arg;
	if (data->victory_nb > 0)
	{
		idx = 0;
		while (idx < data->nb_philo)
		{
			sem_wait(data->sem_satieted);
			idx++;
		}
		if (!data->philo_died)
		{
			data->philo_satieted = true;
			print_end(NULL, data, FULL);
			sem_post(data->sem_died);
		}
	}
	sem_close(data->sem_satieted);
	sem_unlink("/sem_satieted");
	return (data);
}

/*
** Loop through each philo to close and unlink their semaphores and free its
** name. If there is a victory nb it unlocks the semaphore to terminates
** satieted_monitor. Then it closes each semaphore and unlinks them, free philo,
** and join satieted_thread
*/

static void	clean_prog(t_philo *philo, t_data *data, int err, pthread_t th)
{
	if (err != 0)
		print_error(err);
	err = 0;
	data->philo_died = true;
	while (err < (int)data->nb_philo)
	{
		if (philo[err].num)
		{
			sem_close(philo[err].sem);
			sem_close(philo[err].sem_fork);
			sem_unlink(philo[err].name);
			free(philo[err].name);
		}
		if (data->victory_nb > 0 && !data->philo_satieted)
			sem_post(data->sem_satieted);
		err++;
	}
	sem_close(data->write_lock);
	sem_close(data->sem_died);
	sem_unlink("/sem_died");
	sem_unlink("/write");
	sem_unlink("/forks");
	free(philo);
	pthread_join(th, NULL);
}

/*
** Call parser to check entries and initialize data struc. Then malloc
** philosophers and initialize them with init. Once each philosopher
** is create, it runs the satieted_monitor to check victory_condition.
** Then it sem_wait the death of a philo until killing and waiting each process
** (to avoid zombie and leaks).
** At the end it calls clean_prog to free and destroy everything
*/

int			main(int ac, char **av)
{
	int			err;
	int			idx;
	t_data		data;
	t_philo		*philo;
	pthread_t	full_th;

	if ((err = parser(ac, av, &data)) != 0)
		return (print_error(err));
	else
	{
		if (!(philo = (t_philo *)malloc(sizeof(t_philo) * data.nb_philo)))
			return (print_error(MALLOC));
		philo = memset(philo, 0, sizeof(t_philo) * data.nb_philo);
		if ((err = init(&philo, &data)) == 0
			&& pthread_create(&full_th, NULL, &satieted_monitor, &data) == 0)
			sem_wait(data.sem_died);
		idx = -1;
		while (++idx < (int)data.nb_philo)
		{
			kill(philo[idx].pid_id, SIGKILL);
			waitpid(philo[idx].pid_id, NULL, 0);
		}
		clean_prog(philo, &data, err, full_th);
	}
	return (0);
}
