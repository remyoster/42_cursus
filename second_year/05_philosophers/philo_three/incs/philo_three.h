/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:32:43 by roster            #+#    #+#             */
/*   Updated: 2020/10/08 11:06:37 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

/*
** String.h for size_t, pthread.h for threading, stdbool.h for bool types,
** semaphore.h for semaphores and errcode.h for errors macro
*/

# include <string.h>
# include <pthread.h>
# include <stdbool.h>
# include <semaphore.h>
# include "errcode.h"

/*
** Status macros
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
** - sem_died : semaphore to toggle death
** - write_lock : semaphore to avoid print confusion
** - sem_satieted : semaphore to toggle victory condition
** - nb_philo : number of philosophers [argv1]
** - time_to_die : time to die since start of simulation or last meal [argv2]
** - time_to_eat : time to eat [argv3]
** - time_to_sleep : tiem to sleep [argv4]
** - victory_nb : number of meal each philosopher should eat to stop the dinner
** - satieted_philo : number of philosopher which are full
** - t0 : start time of the simulation
*/

typedef struct		s_data
{
	bool			philo_died;
	bool			philo_satieted;
	sem_t			*sem_died;
	sem_t			*write_lock;
	sem_t			*sem_satieted;
	unsigned int	nb_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	victory_nb;
	unsigned int	t0;
}					t_data;

/*
** Philo struct :
** - name : philo name for semaphore purpose
** - satieted : to know if the philosopher if full (in case of victory_nb)
** - sem : semaphore to lock the philosopher (avoid monitor confusion)
** - sem_fork : semaphore to toggle forks
** - pid_id : pid ID of the process
** - data : data struct pointer
** - thread_id : thread ID of the monitor thread
** - num : number of the philosopher (start at 1)
** - last_time_eat : the last time the philosopher has eaten (or t0)
** - nb_meal : number of time the philosopher has eaten
*/

typedef struct		s_philo
{
	char			*name;
	bool			satieted;
	sem_t			*sem;
	sem_t			*sem_fork;
	pid_t			pid_id;
	t_data			*data;
	pthread_t		thread_id;
	unsigned int	num;
	unsigned int	last_time_eat;
	unsigned int	nb_meal;
}					t_philo;

/*
** main functions
*/

int					parser(int ac, char **av, t_data *data);
int					init(t_philo **philo, t_data *data);
bool				eat(t_philo *philo);
bool				fall_asleep(t_philo *philo);
bool				think(t_philo *philo);
void				monitor(t_philo *philo, t_data *data);
sem_t				*init_sem(const char *name, unsigned int val);

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
void				print_end(t_philo *philo, t_data *data, int status);

/*
** utils functions
*/

int					ft_atoi(const char *str);
char				*ft_strcpy(char *dest, const char *src);
void				ft_putchar(char c);
void				ft_putnbr(unsigned int n);
void				ft_putstr(const char *s);
size_t				ft_strlen(const char *s);

#endif
