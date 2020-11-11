/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:32:43 by roster            #+#    #+#             */
/*   Updated: 2020/09/01 08:51:11 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

/*
** String.h for size_t, pthread.h for threading, stdbool.h for bool types and
** errcode for errors macro
*/

# include <string.h>
# include <pthread.h>
# include <stdbool.h>
# include "errcode.h"

/*
** Status macro
*/

# define TAKE_FORK 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DIED 4
# define FULL 5

/*
** Each time is in ms, each philo shared theese vars :
** - philo_died : bool condition to stop thread
** - nb_philo : number of philosophers [argv1]
** - time_to_die : time to die since start of simulation or last meal [argv2]
** - time_to_eat : time to eat [argv3]
** - time_to_sleep : tiem to sleep [argv4]
** - victory_nb : number of meal each philosopher should eat to stop the dinner
** - satieted_philo : number of philosopher which are full
** - t0 : start time of the simulation
** - write_lock : mutex to avoid print confusion
*/

typedef struct		s_data
{
	bool			philo_died;
	unsigned int	nb_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	victory_nb;
	unsigned int	satieted_philo;
	unsigned int	t0;
	pthread_mutex_t	write_lock;
}					t_data;

/*
** Forks struct protected by mutex to avoid duplicating
*/

typedef struct		s_fork
{
	pthread_mutex_t	mutex;
}					t_fork;

/*
** Philo struct :
** - satieted : to know if the philosopher if full (in case of victory_nb)
** - r/l_fork : respectively right and left fork pointer
** - data : data struct pointer
** - num : number of the philosopher (start at 1)
** - last_time_eat : the last time the philosopher has eaten (or t0)
** - nb_meal : number of time the philosopher has eaten
** - mutex : mutex to avoid confusion with monitor
*/

typedef struct		s_philo
{
	bool			satieted;
	t_fork			*r_fork;
	t_fork			*l_fork;
	t_data			*data;
	pthread_t		thread_id;
	unsigned int	num;
	unsigned int	last_time_eat;
	unsigned int	nb_meal;
	pthread_mutex_t	mutex;
}					t_philo;

/*
** main functions
*/

int					parser(int ac, char **av, t_data *data);
int					init(t_philo **philo, t_fork **forks, t_data *data);
bool				eat(t_philo *philo);
bool				fall_asleep(t_philo *philo);
bool				think(t_philo *philo);

/*
** time functions
*/

void				ft_usleep(unsigned int n);
unsigned int		get_time(void);
unsigned int		diff_time(unsigned int t0);

/*
** print functions
*/

int					print_error(int err);
void				usage(void);
void				print_status(t_philo *philo, int status, bool lock);
void				print_end(t_philo *philo, int status);

/*
** utils functions
*/

int					ft_atoi(const char *str);
void				ft_putchar(char c);
void				ft_putnbr(unsigned int n);
void				ft_putstr(const char *s);
size_t				ft_strlen(const char *s);

#endif
