/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 10:38:26 by roster            #+#    #+#             */
/*   Updated: 2020/09/01 09:22:55 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
** Print programm's usage
*/

void	usage(void)
{
	ft_putstr("usage: ./philo_one|two|three nb_philo time_to_die time_to_eat");
	ft_putstr(" time_to_sleep [nb_meat]\n");
	ft_putstr("- nb_philo = number of philosophers and forks\n");
	ft_putstr("- time_to_die = time (in ms) before a philosopher dies if he");
	ft_putstr(" doesn't eat\n");
	ft_putstr("- time_to_eat = duration time (in ms) of eating\n");
	ft_putstr("- time_to_sleep = duration time (in ms) of sleeping\n");
	ft_putstr("- [nb_meat] = optional number of meats a philosopher needs to");
	ft_putstr(" eat before the game stops\n");
}

/*
** Print the status of a philosohper. Lock bool permit to lock or not the write
** mutex. Static sentences is for performance reason. So if lock is true, the
** function lock the write_mutex and print the diff time since the simulation
** began with the num of the philosopher and his status
*/

void	print_status(t_philo *philo, int status, bool lock)
{
	unsigned int		ms;
	static const char	sentences[5][19] = {
		" has taken a fork\n",
		" is eating\n",
		" is sleeping\n",
		" is thinking\n",
		" died\n"
	};

	if (lock)
		pthread_mutex_lock(&philo->data->write_lock);
	if (!philo->data->philo_died)
	{
		ms = diff_time(philo->data->t0);
		ft_putnbr(ms);
		ft_putchar('\t');
		ft_putnbr(philo->num);
		ft_putstr(sentences[status]);
	}
	if (lock)
		pthread_mutex_unlock(&philo->data->write_lock);
}

/*
** Print the end message of the simulation (either died or full). it locks
** the write mutex, print the message with time and put the philo_died condition
** to true (in order to stop threads)
*/

void	print_end(t_philo *philo, int status)
{
	unsigned int	ms;

	pthread_mutex_lock(&philo->data->write_lock);
	if (status == DIED)
		print_status(philo, DIED, false);
	else
	{
		ms = diff_time(philo->data->t0);
		ft_putnbr(ms);
		ft_putchar('\t');
		ft_putstr("Philosophers are full, they're going to exercice..\n");
	}
	philo->data->philo_died = true;
	pthread_mutex_unlock(&philo->data->write_lock);
}

/*
** Print error with err "dispatcher". See errcode.h
*/

int		print_error(int err)
{
	if (err == NB_ARG)
		ft_putstr("Error: Too many/few arguments\n");
	else if (err == NEGATIVE_NUMBER)
		ft_putstr("Error: Negative numbers aren't allowed\n");
	else if (err == NB_PHILO)
		ft_putstr("Error: Two few philosophers/forks\n");
	else if (err == INSTANT_ACTION)
		ft_putstr("Error: Actions can't be instantaneous, time must be > 0\n");
	else if (err == THREAD)
		ft_putstr("Error: thread error occurs\n");
	else if (err == MALLOC)
		ft_putstr("Error: malloc failed\n");
	else if (err == MUTEX)
		ft_putstr("Error: mutex failed\n");
	if (err != THREAD && err != MALLOC && err != MUTEX)
		usage();
	return (err);
}
