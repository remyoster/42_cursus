/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:28:21 by roster            #+#    #+#             */
/*   Updated: 2019/02/11 19:22:23 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../libft/libft.h"
#include <stdlib.h>

static void	ft_fill_map(size_t i, t_pix **map, char **tmp, char *line)
{
	size_t j;

	j = 0;
	while (tmp[j] != 0)
	{
		map[i][j].z = ft_atoi(tmp[j]);
		if (ft_strchr(tmp[j], ',') != NULL)
		{
			ft_strclr(line);
			line = ft_strsub(ft_strchr(tmp[j], 'x'), 1, 6);
			map[i][j].h = ft_atoi_base_fdf(line);
			map[i][j].tmp = map[i][j].h;
			ft_strdel(&line);
		}
		else
		{
			map[i][j].h = -1;
			map[i][j].tmp = map[i][j].h;
		}
		j++;
	}
}

t_pix		**ft_create_map(int fd, t_pos pos)
{
	t_pix	**map;
	char	**tmp;
	char	*line;
	size_t	i;

	i = 0;
	if (!(map = (t_pix**)malloc(sizeof(t_pix*) * pos.y)))
		return (0);
	while (i < pos.y)
	{
		if (!(map[i] = (t_pix*)malloc(sizeof(t_pix) * pos.x)))
			return (0);
		i++;
	}
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		ft_fill_map(i, map, tmp, line);
		ft_tabdel_char(&tmp);
		ft_strdel(&line);
		i++;
	}
	return (map);
}
