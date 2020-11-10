/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:56:13 by roster            #+#    #+#             */
/*   Updated: 2020/10/08 08:50:54 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/*
** Thread starts function.
** While nobody dies a philosopher eat/sleep/think. If someone dies the loop
** stop and the thread terminates
*/

static void	*thread_start(void *arg)
{
	t_philo *philo;

	philo = arg;
	if (philo->num % 2 == 0)
		ft_usleep(500);
	while (1)
	{
		if (!(eat(philo)) || !(fall_asleep(philo)) || !(think(philo)))
			break ;
	}
	return (philo);
}

/*
** Create the semaphore name for a philosopher based on his number
** Returns "/philo_[nb]"
*/

static char	*make_philo_name(unsigned int philo_num)
{
	size_t	idx;
	char	*philo_name;

	if (!(philo_name = (char *)malloc(sizeof(char) * ft_strlen("/philo") + 10)))
		return (NULL);
	idx = ft_strlen("/philo");
	philo_name = ft_strcpy(philo_name, "/philo");
	while (philo_num > 0)
	{
		philo_name[idx] = philo_num % 10 + 48;
		philo_num /= 10;
		idx++;
	}
	philo_name[idx] = '\0';
	return (philo_name);
}

/*
** Initialize each philo structure before forking them
*/

int			init_philo(t_philo *philo, t_data *data, sem_t *forks, size_t idx)
{
	philo->num = idx + 1;
	philo->satieted = false;
	philo->data = data;
	philo->nb_meal = 0;
	philo->last_time_eat = data->t0;
	philo->sem_fork = forks;
	philo->name = make_philo_name(idx + 1);
	if (!(philo->sem = init_sem(philo->name, 1)))
		return (SEM);
	return (0);
}

/*
** Start the thread for eat/sleep/think and monitor death condition
*/

static void	init_fork(t_philo *philo, t_data *data)
{
	if (pthread_create(&philo->thread_id, NULL,
		&thread_start, philo) != 0)
	{
		print_error(THREAD);
		exit(EXIT_FAILURE);
	}
	monitor(philo, data);
	pthread_join(philo->thread_id, NULL);
	exit(EXIT_SUCCESS);
}

/*
** Initialize forks semaphore and create a process for each philosopher then
** if the process is a fork it initialize it. If its the main it continues until
** each fork is made
*/

int			init(t_philo **philo, t_data *data)
{
	size_t	idx;
	sem_t	*forks;
	int		err;

	idx = 0;
	data->t0 = get_time();
	if (!(forks = init_sem("/forks", data->nb_philo)))
		return (SEM);
	while (idx < data->nb_philo)
	{
		if ((err = init_philo(&(*philo)[idx], data, forks, idx)) != 0)
			return (err);
		(*philo)[idx].pid_id = fork();
		if ((*philo)[idx].pid_id == -1)
			return (FORK);
		else if ((*philo)[idx].pid_id == 0)
			init_fork(&(*philo)[idx], data);
		idx += 1;
	}
	return (err || 0);
}
