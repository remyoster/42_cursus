/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 10:49:29 by roster            #+#    #+#             */
/*   Updated: 2019/01/11 12:31:18 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	ft_check_1(char *s, size_t i)
{
	if (s[i] == s[i + 2])
	{
		if (s[i] == s[i + 3] || s[i] == s[i + 4] ||
				s[i] == s[i + 5] || s[i] == s[i + 6])
			return (1);
		else
			return (0);
	}
	else if (s[i] == s[i + 3] && s[i] == s[i + 4])
		return (1);
	else if (s[i] == s[i + 4])
	{
		if (s[i] == s[i + 5] || s[i] == s[i + 8])
			return (1);
		else
			return (0);
	}
	else if (s[i] == s[i + 5])
	{
		if (s[i] == s[i + 6] || s[i] == s[i + 9])
			return (1);
		else
			return (0);
	}
	return (0);
}

static int	ft_check_4(char *s, size_t i)
{
	if (s[i] == s[i + 5])
	{
		if (s[i] == s[i + 6] || s[i] == s[i + 8] || s[i] == s[i + 9])
			return (1);
		else
			return (0);
	}
	else if (s[i] == s[i + 7] && s[i] == s[i + 8])
		return (1);
	else if (s[i] == s[i + 8])
	{
		if (s[i] == s[i + 9] || s[i] == s[i + 12])
			return (1);
		else
			return (0);
	}
	return (0);
}

static int	ft_check_content_tetri(char *tetri)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (ft_strlen(tetri) != 16)
		ft_usage(-1);
	while (tetri[i] != '\0')
	{
		if (tetri[i] != '.' && tetri[i] != '#')
			ft_usage(-1);
		if (tetri[i] == '#')
			count++;
		i++;
	}
	if (count == 4)
		return (1);
	else
		return (0);
}

int			ft_check_tetri(char *s)
{
	size_t	i;

	if (ft_check_content_tetri(s) != 1)
		ft_usage(-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (s[i] == s[i + 1])
				return (ft_check_1(s, i));
			else if (s[i] == s[i + 2] && s[i] == s[i + 3] && s[i] == s[i + 4])
				return (1);
			else if (s[i] == s[i + 3] && s[i] == s[i + 4])
			{
				if (s[i] == s[i + 5] || s[i] == s[i + 7] || s[i] == s[i + 8])
					return (1);
			}
			else if (s[i] == s[i + 4])
				return (ft_check_4(s, i));
		}
		i++;
	}
	ft_usage(-1);
	return (0);
}

int			ft_check_file(int fd, t_pos pos)
{
	char	*line;
	char	*tetri;

	pos.i = 0;
	if (!(tetri = ft_strnew(1)))
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_check_and_join(&line, &tetri, 0) == 1)
		{
			if ((int)ft_strlen(tetri) != pos.y * 4)
				ft_usage(-1);
			pos.x++;
		}
		pos.y++;
		ft_check_content(tetri, &pos);
	}
	if (pos.y != 0)
		ft_usage(-1);
	ft_strdel(&tetri);
	return (pos.i);
}
