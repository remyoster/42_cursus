/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:17:40 by roster            #+#    #+#             */
/*   Updated: 2019/01/10 19:08:02 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_protec_y(char **tetri, t_pos *pos, t_mark *mark)
{
	pos->x = 0;
	if (mark->map[pos->y + 1] != 0)
		pos->y++;
	else
		mark->map = ft_reset_map(tetri, pos, mark);
}

static void	ft_tetri_dot(char **tetri, t_pos *pos, t_mark *mark)
{
	if (ft_isalpha(mark->map[pos->y][pos->x]) == 1)
	{
		ft_place_mark(tetri, pos, mark);
		pos->j++;
		pos->x++;
	}
	else if (mark->map[pos->y][pos->x] == '\n')
	{
		if (pos->j == 0)
			ft_protec_y(tetri, pos, mark);
		else
			ft_backtrack(tetri, pos, mark);
	}
	else if (mark->map[pos->y][pos->x] == '.')
	{
		ft_place_mark(tetri, pos, mark);
		pos->j++;
		pos->x++;
	}
}

static void	ft_tetri_backsl(char **tetri, t_pos *pos, t_mark *mark)
{
	if (mark->map[pos->y + 1] != 0)
	{
		pos->x = mark->x;
		pos->y++;
		pos->j++;
	}
	else if (pos->i == 0 && mark->map[pos->y + 1] == 0)
		mark->map = ft_reset_map(tetri, pos, mark);
	else
		ft_backtrack(tetri, pos, mark);
}

static void	ft_tetri_alpha(char **tetri, t_pos *pos, t_mark *mark)
{
	if (ft_isalpha(mark->map[pos->y][pos->x]) == 1)
	{
		if (pos->j == 0)
			pos->x++;
		else
			ft_backtrack(tetri, pos, mark);
	}
	else if (mark->map[pos->y][pos->x] == '\n')
	{
		if (pos->j == 0)
			ft_protec_y(tetri, pos, mark);
		else if (pos->i == 0 && mark->map[pos->y + 1] == 0)
			mark->map = ft_reset_map(tetri, pos, mark);
		else
			ft_backtrack(tetri, pos, mark);
	}
	else if (mark->map[pos->y][pos->x] == '.')
	{
		ft_place_mark(tetri, pos, mark);
		mark->map[pos->y][pos->x++] = tetri[pos->i][pos->j++];
	}
}

char		**ft_resolve(char **tetri, t_pos *pos, t_mark *mark)
{
	mark->map_size = 0;
	pos->i = 0;
	pos->j = 0;
	pos->x = 0;
	pos->y = 0;
	while (tetri[pos->i] != 0)
	{
		while (tetri[pos->i][pos->j])
		{
			if (tetri[pos->i][pos->j] == '.')
				ft_tetri_dot(tetri, pos, mark);
			if (tetri[pos->i][pos->j] == '\n')
				ft_tetri_backsl(tetri, pos, mark);
			if (ft_isalpha(tetri[pos->i][pos->j]) == 1)
				ft_tetri_alpha(tetri, pos, mark);
		}
		pos->i++;
		pos->j = 0;
		pos->x = 0;
		pos->y = 0;
	}
	return (mark->map);
}
