/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:28:51 by roster            #+#    #+#             */
/*   Updated: 2019/02/11 19:12:51 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/fdf.h"
#include <stdlib.h>

static size_t	ft_strlen_tab(char **tmp)
{
	size_t i;

	i = 0;
	while (tmp[i] != 0)
		i++;
	if (i == 0)
		ft_usage(1);
	return (i);
}

static size_t	ft_check_hexa(char *str, char *s)
{
	size_t	j;

	j = 0;
	if (s[j] == '-')
		j++;
	while (s[j])
	{
		if (s[j] == ',')
			break ;
		if (s[j] < 48 || s[j] > 57)
			ft_usage(1);
		j++;
	}
	if ((s[0] == '-' && j > 8) || (s[0] != '-' && j > 7) ||
			str[1] != '0' || str[2] != 'x' || ft_strlen(str) > 9)
		ft_usage(1);
	j = 3;
	while (str[j])
	{
		if (str[j] < 48 || (str[j] > 57 && str[j] < 65) ||
				(str[j] > 70 && str[j] < 97) || str[j] > 102)
			ft_usage(1);
		j++;
	}
	return (1);
}

static void		ft_check_line(char **tmp)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (tmp[i] != 0)
	{
		j = 0;
		while (tmp[i][j] != '\0')
		{
			if (j == 0 && (str = ft_strchr(tmp[i], ',')) != NULL)
				if (ft_check_hexa(str, tmp[i]) == 1)
					break ;
			if (tmp[i][j] == '-')
				j++;
			if ((tmp[i][0] == '-' && ft_strlen(tmp[i]) > 7) ||
					(tmp[i][0] != '-' && ft_strlen(tmp[i]) > 6))
				ft_usage(1);
			if (tmp[i][j] < 48 || tmp[i][j] > 57)
				ft_usage(1);
			j++;
		}
		i++;
	}
}

t_pos			ft_check_file(int fd)
{
	t_pos	pos;
	char	**tmp;
	char	*line;

	pos.x = 0;
	pos.y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		ft_check_line(tmp);
		if (pos.x == 0)
		{
			pos.x = ft_strlen_tab(tmp);
			if (pos.x > 2560)
				ft_usage(1);
		}
		if (pos.x != ft_strlen_tab(tmp))
			ft_usage(1);
		ft_tabdel_char(&tmp);
		ft_strdel(&line);
		pos.y++;
		if (pos.y > 1440)
			ft_usage(1);
	}
	return (pos);
}
