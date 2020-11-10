/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:56:13 by roster            #+#    #+#             */
/*   Updated: 2020/10/09 10:40:24 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

/*
** Thread starts function.
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
** In order to work around the non closing semaphore after program interuption
** we need to unlink it first to be sure we can create it.
** see man sem_open for flags and mods. If still troubles check /dev/shm/
** and delete names you need (if sure they aren't use anywhere else)
*/

sem_t		*init_sem(const char *name, unsigned int val)
{
	sem_t	*sem;

	sem_unlink(name);
	sem = sem_open(name, O_CREAT | O_EXCL, 00664, val);
	if (sem == SEM_FAILED)
		return (NULL);
	return (sem);
}

/*
** Create the semaphore name for a philosopher based on his number
** Returns "/philo_[nb]"
*/

static char	*make_philo_name(unsigned int philo_num)
{
	size_t	idx;
	char	*philo_name;

	if (!(philo_name = (char*)malloc(sizeof(char) * ft_strlen("/philo") + 10)))
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
** Initialize forks semaphore
** Initialize each philosopher with his respective data and starts each thread
*/

int			init(t_philo **philo, t_data *data)
{
	size_t	idx;
	sem_t	*forks;

	if (!(forks = init_sem("/forks", data->nb_philo)))
		return (SEM);
	idx = 0;
	data->t0 = get_time();
	while (idx < data->nb_philo)
	{
		(*philo)[idx].num = idx + 1;
		(*philo)[idx].satieted = false;
		(*philo)[idx].data = data;
		(*philo)[idx].nb_meal = 0;
		(*philo)[idx].sem_fork = forks;
		(*philo)[idx].name = make_philo_name(idx + 1);
		if (!((*philo)[idx].sem = init_sem((*philo)[idx].name, 1)))
			return (SEM);
		(*philo)[idx].last_time_eat = data->t0;
		if (pthread_create(&(*philo)[idx].thread_id, NULL,
			&thread_start, &(*philo)[idx]) != 0)
			return (THREAD);
		idx += 1;
	}
	return (0);
}
