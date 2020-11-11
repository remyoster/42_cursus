/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_no_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:20:17 by roster            #+#    #+#             */
/*   Updated: 2019/01/10 11:18:45 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int		main(int argc, char	**argv)
{
	int fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((get_next_line(fd, &line)) > 0)
		{
			printf("|%s|\n", line);
			free(line);
		}
		printf("Retour final = |%d|\n", get_next_line(fd, &line));
		if (close(fd) == -1)
			return (1);
	}
	return (0);
}
