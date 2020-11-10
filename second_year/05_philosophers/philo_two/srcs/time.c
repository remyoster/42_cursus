/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 08:19:56 by roster            #+#    #+#             */
/*   Updated: 2020/08/25 09:34:05 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>

/*
** Returns the timestamp in milliseconds
*/

unsigned int	get_time(void)
{
	struct timeval	tp;
	unsigned int	milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

/*
** Return the time between start and the call of diff_time.
** t0 must be < get_time()
*/

unsigned int	diff_time(unsigned int t0)
{
	return (get_time() - t0);
}

/*
** Better accurate usleep function. Loops on a small usleep time until it
** reaches the limit time n
*/

void			ft_usleep(unsigned int n)
{
	struct timeval	t0;
	struct timeval	tmp;
	unsigned int	diff;

	gettimeofday(&t0, NULL);
	diff = 0;
	while (diff < n)
	{
		usleep(50);
		gettimeofday(&tmp, NULL);
		diff = (tmp.tv_sec - t0.tv_sec) * 1000000 + (tmp.tv_usec - t0.tv_usec);
	}
}
