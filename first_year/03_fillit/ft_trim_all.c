/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 10:10:21 by roster            #+#    #+#             */
/*   Updated: 2019/01/10 15:41:33 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static char	*ft_trim_end_dot(char *tmp_cut)
{
	int		i;
	int		j;
	char	*tmp;

	i = ft_strlen(tmp_cut) - 1;
	j = 0;
	while (i > 0)
	{
		if (tmp_cut[i] == '#')
			break ;
		j++;
		i--;
	}
	if (j > 0)
		tmp = ft_strsub(tmp_cut, 0, i + 1);
	else
		tmp = ft_strsub(tmp_cut, 0, ft_strlen(tmp_cut) - 1);
	if (!tmp)
		return (NULL);
	ft_strdel(&tmp_cut);
	return (tmp);
}

static char	*ft_trim_begin_dot(char *tmp)
{
	int		i;
	char	*tmp_cut;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '#')
			break ;
		i++;
	}
	if (i >= 5 && i < 10)
		tmp_cut = ft_strsub(tmp, 5, ft_strlen(tmp) - 5);
	else if (i >= 10 && i < 15)
		tmp_cut = ft_strsub(tmp, 10, ft_strlen(tmp) - 10);
	else if (i == 15)
		tmp_cut = ft_strsub(tmp, i, ft_strlen(tmp) - 15);
	else
		tmp_cut = ft_strdup(tmp);
	if (!tmp_cut)
		return (NULL);
	return (ft_trim_end_dot(tmp_cut));
}

static char	*ft_tetri_to_0(char *str)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (str[i] != '#' && str[i] == str[i + 5] && str[i] == str[i + 10]
				&& str[i] == str[i + 15])
		{
			str[i] = 48;
			str[i + 5] = 48;
			str[i + 10] = 48;
			str[i + 15] = 48;
		}
		i++;
	}
	return (str);
}

char		*ft_trim_all(char *str)
{
	int		i;
	char	**tmp;
	char	*tmp_cut;

	i = 0;
	if (!(tmp_cut = ft_trim_begin_dot(ft_tetri_to_0(str))))
		return (NULL);
	if (!(tmp = ft_strsplit(tmp_cut, '0')))
		return (NULL);
	ft_strclr(tmp_cut);
	while (tmp[i] != 0)
	{
		if (!(tmp_cut = ft_strjoin_free(tmp_cut, tmp[i], 0)))
			return (NULL);
		if (tmp[i + 1] != 0)
			if (!(tmp_cut = ft_strjoin_free(tmp_cut, "\n", 1)))
				return (NULL);
		i++;
	}
	free(tmp);
	return (tmp_cut);
}
