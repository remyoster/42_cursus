/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:56:13 by roster            #+#    #+#             */
/*   Updated: 2020/09/01 08:36:54 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
** Thread starts function. If philosopher is even it waits 500us to avoid to
** much waiting time to take forks.
** While nobody dies a philosopher eat/sleep/think. If someone dies the loop
** stop and the thread terminates
*/

static void	*thread_start(void *arg)
{
	t_philo	*philo;

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
** Create the fork mutex
*/

static int	init_forks(t_fork **forks, unsigned int nb_philo)
{
	size_t idx;

	idx = 0;
	while (idx < nb_philo)
	{
		if (pthread_mutex_init(&(*forks)[idx].mutex, NULL) != 0)
			return (MUTEX);
		idx++;
	}
	return (0);
}

/*
** Initialize forks
** Initialize each philosopher with his respective data and starts each thread
*/

int			init(t_philo **philo, t_fork **forks, t_data *data)
{
	int		err;
	size_t	idx;

	idx = 0;
	data->t0 = get_time();
	err = init_forks(forks, data->nb_philo);
	while (idx < data->nb_philo && err == 0)
	{
		if (pthread_mutex_init(&(*philo)[idx].mutex, NULL) != 0)
			err = MUTEX;
		(*philo)[idx].num = idx + 1;
		(*philo)[idx].satieted = false;
		(*philo)[idx].data = data;
		(*philo)[idx].nb_meal = 0;
		(*philo)[idx].r_fork = &(*forks)[idx];
		(*philo)[idx].l_fork = idx > 0 ? &(*forks)[idx - 1]
			: &(*forks)[data->nb_philo - 1];
		(*philo)[idx].last_time_eat = data->t0;
		if (pthread_create(&(*philo)[idx].thread_id, NULL,
			&thread_start, &(*philo)[idx]) != 0)
			err = THREAD;
		idx += 1;
	}
	return (err);
}
