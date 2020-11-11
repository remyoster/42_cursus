/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:34:57 by roster            #+#    #+#             */
/*   Updated: 2019/01/10 19:10:25 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_place_mark(char **tetri, t_pos *pos, t_mark *mark)
{
	if (pos->j == 0)
		mark->x = pos->x;
	if (tetri[pos->i][pos->j + 1] == '\0')
	{
		mark->tab[pos->i][0] = mark->x;
		mark->tab[pos->i][1] = pos->x;
		mark->tab[pos->i][2] = pos->y;
	}
}

void	ft_backtrack(char **tetri, t_pos *pos, t_mark *mark)
{
	int	nb_alpha;

	nb_alpha = ft_strnchr_count(tetri[pos->i], pos->i + 65, 0, pos->j);
	while (nb_alpha > 0)
	{
		if (mark->map[pos->y][pos->x] == pos->i + 65)
		{
			mark->map[pos->y][pos->x] = '.';
			nb_alpha--;
		}
		pos->x--;
		if (pos->x < 0 && nb_alpha > 0)
		{
			pos->x = ft_map_area(mark->map_size, mark->nb_tetri);
			pos->y--;
		}
	}
	pos->x = mark->x + 1;
	pos->j = 0;
}

char	**ft_reset_map(char **tetri, t_pos *pos, t_mark *mark)
{
	if (pos->i > 0)
	{
		ft_backtrack(tetri, pos, mark);
		pos->i--;
		pos->j = ft_strlen(tetri[pos->i]);
		mark->x = mark->tab[pos->i][0];
		pos->x = mark->tab[pos->i][1];
		pos->y = mark->tab[pos->i][2];
		ft_backtrack(tetri, pos, mark);
		return (mark->map);
	}
	mark->map_size++;
	pos->i = 0;
	pos->j = 0;
	pos->x = 0;
	pos->y = 0;
	ft_tabdel(mark->map);
	if (!(mark->map = ft_create_map(mark->map_size, mark->nb_tetri)))
		exit(1);
	return (mark->map);
}
