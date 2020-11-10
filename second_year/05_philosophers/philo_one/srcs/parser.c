/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 10:40:58 by roster            #+#    #+#             */
/*   Updated: 2020/09/01 09:32:17 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
** Initliaze the data structure with numbers parsed and write mutex
*/

static int	init_data(t_data *data, int nb[5])
{
	data->nb_philo = nb[0];
	data->time_to_die = nb[1];
	data->time_to_eat = nb[2];
	data->time_to_sleep = nb[3];
	data->victory_nb = nb[4];
	data->satieted_philo = 0;
	data->philo_died = false;
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (THREAD);
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
