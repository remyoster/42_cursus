/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 10:40:58 by roster            #+#    #+#             */
/*   Updated: 2020/10/08 11:08:47 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <fcntl.h>
#include <sys/stat.h>

/*
** In order to work around the non closing semaphore after program interuption
** we need to unlink it first to be sure we can create it.
** see man sem_open for flags and mods. If still troubles check /dev/shm/
** and delete names you need (if sure they aren't use anywhere else)
*/

sem_t		*init_sem(const char *name, unsigned int val)
{
	sem_t *sem;

	sem_unlink(name);
	sem = sem_open(name, O_CREAT | O_EXCL, 00664, val);
	if (sem == SEM_FAILED)
		return (NULL);
	return (sem);
}

static int	init_data(t_data *data, int nb[5])
{
	data->nb_philo = nb[0];
	data->time_to_die = nb[1];
	data->time_to_eat = nb[2];
	data->time_to_sleep = nb[3];
	data->victory_nb = nb[4];
	data->philo_died = false;
	data->philo_satieted = false;
	if (!(data->write_lock = init_sem("/write_lock", 1))
		|| !(data->sem_died = init_sem("/sem_died", 0))
		|| !(data->sem_satieted = init_sem("/sem_satieted", 0)))
		return (SEM);
	return (0);
}

/*
** Parsed argv to check if there are no ;
** - negative numbers
** - 0 numbers
** - too much args or too few args
** - too few philosphers (2 min)
** Then init data and returns err (== 0 if nothing went wrong)
*/

int			parser(int ac, char **av, t_data *data)
{
	size_t	idx;
	int		nb[5];

	if (ac < 5 || ac > 6)
		return (NB_ARG);
	if ((nb[0] = ft_atoi(av[1])) < 2)
		return (NB_PHILO);
	idx = 1;
	while (++idx < (size_t)ac)
	{
		nb[idx - 1] = ft_atoi(av[idx]);
		if (nb[idx - 1] < 0)
			return (NEGATIVE_NUMBER);
		else if (nb[idx - 1] == 0)
			return (INSTANT_ACTION);
	}
	if (idx == 5)
		nb[4] = 0;
	return (init_data(data, nb));
}
