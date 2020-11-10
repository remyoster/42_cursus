/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_to_alpha.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:57:30 by roster            #+#    #+#             */
/*   Updated: 2019/01/11 12:25:19 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static char	**ft_fill_alpha(char *str, char **tetri, int x)
{
	int		i;
	char	*tmp_cut;

	i = 0;
	if (!(tmp_cut = ft_trim_all(str)))
		exit(1);
	while (tmp_cut[i] != '\0')
	{
		if (tmp_cut[i] == '#')
			tmp_cut[i] = tmp_cut[i] + 30 + x;
		i++;
	}
	tetri[x] = ft_strdup(tmp_cut);
	ft_strdel(&tmp_cut);
	return (tetri);
}

char		**ft_tetri_to_alpha(char **tetri, int fd)
{
	int		i;
	int		x;
	char	*line;
	char	*str;

	i = 0;
	x = 0;
	str = ft_strnew(1);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_check_and_join(&line, &str, 1) == 1)
		{
			i++;
			if (i % 4 == 0)
			{
				if (!(tetri = ft_fill_alpha(str, tetri, x)))
					exit(1);
				ft_strclr(str);
				x++;
			}
		}
	}
	tetri[x] = 0;
	ft_strdel(&str);
	return (tetri);
}
