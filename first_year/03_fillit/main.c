/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:50:43 by roster            #+#    #+#             */
/*   Updated: 2019/01/11 12:20:51 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void	ft_print_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		i++;
	}
	ft_tabdel(map);
}

static int	ft_open_or_close(int bol, int fd, char **argv)
{
	if (bol == 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			exit(1);
	}
	else
	{
		if (close(fd) == -1)
			exit(1);
	}
	return (fd);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	**tetri;
	t_pos	pos;
	t_mark	mark;

	if (argc == 2)
	{
		pos.x = 0;
		pos.y = 1;
		fd = ft_open_or_close(1, 0, argv);
		mark.nb_tetri = ft_check_file(fd, pos);
		if (!(mark.map = ft_create_map(0, mark.nb_tetri)))
			return (0);
		if (!(tetri = (char**)malloc(sizeof(char*) * mark.nb_tetri + 1)))
			return (0);
		ft_open_or_close(0, fd, argv);
		fd = ft_open_or_close(1, 0, argv);
		tetri = ft_tetri_to_alpha(tetri, fd);
		ft_open_or_close(0, fd, argv);
		ft_print_map(ft_resolve(tetri, &pos, &mark));
		ft_tabdel(tetri);
	}
	else
		ft_usage(argc);
	return (0);
}
