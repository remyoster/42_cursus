/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:57:25 by roster            #+#    #+#             */
/*   Updated: 2019/01/11 08:15:42 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		ft_map_area(int map_size, int nb_tetri)
{
	int		lenght;
	int		map_area;
	size_t	i;

	i = 1;
	lenght = 0;
	map_area = nb_tetri * TETRI_AREA;
	while (lenght < map_area)
	{
		lenght = i * i;
		i++;
	}
	lenght = ft_sqrt(lenght) + map_size;
	return (lenght);
}

char	**ft_create_map(int map_size, int nb_tetri)
{
	char	**map;
	int		res;
	int		i;

	i = 0;
	if (nb_tetri == 0)
		ft_usage(-1);
	res = ft_map_area(map_size, nb_tetri);
	if (!(map = (char**)malloc(sizeof(char*) * res + 1)))
		return (NULL);
	while (i < res)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * res + 2)))
			return (NULL);
		ft_memset(map[i], '.', res);
		map[i][res] = '\n';
		map[i][res + 1] = '\0';
		i++;
	}
	map[i] = 0;
	return (map);
}
