/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 07:49:25 by roster            #+#    #+#             */
/*   Updated: 2020/10/08 13:04:33 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

/*
** Boolean check for philo_died condition
*/

static bool	is_alive(t_philo *philo)
{
	return (!philo->data->philo_died);
}

/*
** Toggles forks for each philosopher. If mod == 0 it "locks" two forks with
** semaphore and call print status. If mod != 0 it realeases forks
*/

static void	toggle_forks(t_philo *philo, int mod)
{
	if (mod == 0)
	{
		sem_wait(philo->sem_fork);
		sem_wait(philo->sem_fork);
		sem_wait(philo->data->write_lock);
		print_status(philo, TAKE_FORK, false);
		print_status(philo, TAKE_FORK, false);
		sem_post(philo->data->write_lock);
	}
	else
	{
		sem_post(philo->sem_fork);
		sem_post(philo->sem_fork);
	}
}

/*
** Toggles eating action if every philo is alive.
** It locks the philosopher (to avoid monitor problem)
** then calls toggle_forks and updates his last_time_eat time then waits
** [time_to_eat] time. Once done it checks if the philo is satieted it updates
** the satieted bool and the number of satieted philosophers
*/

bool		eat(t_philo *philo)
{
	if (!is_alive(philo))
		return (false);
	sem_wait(philo->sem);
	toggle_forks(philo, 0);
	print_status(philo, EATING, true);
	philo->last_time_eat = get_time();
	ft_usleep(philo->data->time_to_eat * 1000);
	toggle_forks(philo, 1);
	philo->nb_meal += 1;
	sem_post(philo->sem);
	if (philo->data->victory_nb > 0 && !philo->satieted
		&& philo->nb_meal >= philo->data->victory_nb)
	{
		philo->satieted = true;
		sem_wait(philo->data->write_lock);
		philo->data->satieted_philo += 1;
		sem_post(philo->data->write_lock);
	}
	return (true);
}

/*
** Sleeping function during [time_to_sleep] if every philo is alive
*/

bool		fall_asleep(t_philo *philo)
{
	if (!is_alive(philo))
		return (false);
	print_status(philo, SLEEPING, true);
	ft_usleep(philo->data->time_to_sleep * 1000);
	return (true);
}

/*
** Thinking function if every philo is alive
*/

bool		think(t_philo *philo)
{
	if (!is_alive(philo))
		return (false);
	print_status(philo, THINKING, true);
	return (true);
}
