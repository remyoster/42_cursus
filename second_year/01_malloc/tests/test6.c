/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 08:06:15 by roster            #+#    #+#             */
/*   Updated: 2020/09/03 08:50:26 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/malloc.h"
#include <unistd.h>
#include <string.h>

/*
** Pthread test
*/

/*
** 1024 * 1204 = 1048576
*/

#define M 1048576

pthread_mutex_t	g_write_lock = PTHREAD_MUTEX_INITIALIZER;

void	print(char *s, size_t idx)
{
	char c;

	c = idx + 48;
	pthread_mutex_lock(&g_write_lock);
	write(1, "THREAD ", 7);
	write(1, &c, 1);
	write(1, "\n", 1);
	write(1, s, strlen(s));
	pthread_mutex_unlock(&g_write_lock);
}

void	*thread_start(void *arg)
{
	char	*addr1;
	char	*addr3;
	size_t	*idx;

	idx = arg;
	addr1 = (char *)malloc(16 * M);
	strcpy(addr1, "Bonjour\n");
	print(addr1, *idx + 1);
	addr3 = (char *)realloc(addr1, 128 * M);
	addr3[127 * M] = 42;
	print(addr3, *idx + 1);
	show_alloc_mem();
	free(addr1);
	free(addr3);
	return (arg);
}

int		main(void)
{
	size_t		idx;
	pthread_t	th[3];

	idx = 0;
	while (idx < 3)
	{
		pthread_create(&th[idx], NULL, &thread_start, &idx);
		idx++;
	}
	idx = 0;
	while (idx < 3)
	{
		pthread_join(th[idx], NULL);
		idx++;
	}
	return (0);
}
