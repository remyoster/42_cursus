/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:26:02 by roster            #+#    #+#             */
/*   Updated: 2019/01/10 11:18:34 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int     main(void)
{
	int     fd, fd2, fd3, fd4, fd5;
	int     i;
	char    *line;

	fd = open("test", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	fd3 = open("test3", O_RDONLY);
	fd4 = open("test4", O_RDONLY);
	fd5 = open("test5", O_RDONLY);
	if (fd < 0 || fd2 < 0 || fd3 < 0 || fd4 < 0 || fd5 < 0)
		return (-1);
	printf("Fd open = %d\n", get_next_line(fd5, &line));
	printf("|%s|\n", line);
	free(line);
	if (close(fd5) == -1)
		return (1);
	printf("Fd close = %d\n", get_next_line(fd5, &line));
	i = 0;
	while (i < 10)
	{
		if (i % 2 == 0)
		{
			if (get_next_line(fd, &line) > 0)
			{
				printf("|%s|\n", line);
				free(line);
			}
		}
		else
		{
			if (get_next_line(fd2, &line) > 0)
			{
				printf("|%s|\n", line);
				free(line);
			}
		}
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (i % 2 == 0)
		{
			if (get_next_line(fd3, &line) > 0)
			{
				printf("|%s|\n", line);
				free(line);
			}
		}
		else
		{
			if (get_next_line(fd4, &line) > 0)
			{
				printf("|%s|\n", line);
				free(line);
			}
		}
		i++;
	}
	while(1)
	{}
	if (close(fd) == -1 || close(fd2) == -1 || close(fd3) == -1 || close(fd4) == -1)
		return (1);
	return (0);
}
