/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_and_join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 10:17:47 by roster            #+#    #+#             */
/*   Updated: 2019/01/14 14:11:50 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		ft_check_and_join(char **line, char **tetri, int bol)
{
	if (bol == 1)
	{
		if (ft_strncmp(*line, "", 1) != 0)
		{
			if (!(*tetri = ft_strjoin_free(*tetri, *line, 0)))
				exit(1);
			if (!(*tetri = ft_strjoin_free(*tetri, "\n", 1)))
				exit(1);
			return (1);
		}
		else
			ft_strdel(line);
	}
	else
	{
		if (ft_strncmp(*line, "", 1) != 0)
		{
			if (!(*tetri = ft_strjoin_free(*tetri, *line, 0)))
				exit(1);
			return (1);
		}
		else
			ft_strdel(line);
	}
	return (0);
}

void	ft_check_content(char *tetri, t_pos *pos)
{
	if (pos->y == 5 && pos->x == 4 && pos->i < 26)
	{
		if (ft_check_tetri(tetri) == 0)
			ft_usage(-1);
		ft_strclr(tetri);
		pos->y = 0;
		pos->i++;
		pos->x = 0;
	}
	if (pos->y > 5 || pos->x > 4 || pos->i > 26)
		ft_usage(-1);
}
