/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 07:49:25 by roster            #+#    #+#             */
/*   Updated: 2020/10/08 09:17:34 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
** [time_to_eat] time. Once done it checks if the philo is satieted and increase
** the satieted semaphore
*/

bool		eat(t_philo *philo)
{
	if (!is_alive(philo))
		return (false);
	sem_wait(philo->sem);
	toggle_forks(philo, 0);
	print_status(philo, EATING, true);
	philo->last_time_eat = get_time();
	sem_post(philo->sem);
	ft_usleep(philo->data->time_to_eat * 1000);
	toggle_forks(philo, 1);
	philo->nb_meal += 1;
	if (philo->data->victory_nb > 0 && !philo->satieted
		&& philo->nb_meal >= philo->data->victory_nb)
	{
		philo->satieted = true;
		sem_post(philo->data->sem_satieted);
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
