/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_oxx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:34:31 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 13:57:17 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_xx_next(char *tmp, int bol)
{
	size_t	i;

	i = 0;
	while (tmp[i] == bol)
		i++;
	if (i == 1)
	{
		tmp[0] = 'x';
		tmp = ft_strjoin_free("0", tmp, 2);
	}
	else
	{
		if (bol == '0')
			tmp[1] = 'x';
		else if (bol == ' ' && i != ft_strlen(tmp))
		{
			tmp[i - 1] = 'x';
			tmp[i - 2] = '0';
		}
	}
	return (tmp);
}

static char	*ft_xx(char *tmp, t_flg *flg, const char *fmt, size_t i)
{
	size_t	count;

	i = ft_strlen(tmp) - 1;
	count = ft_strchr_count(tmp, ' ');
	if (tmp[0] == ' ' || (tmp[0] == '0' && ft_strchr(flg->tab, '.') == NULL))
		tmp = ft_xx_next(tmp, tmp[0]);
	else if (ft_strchr(flg->tab, '-') != NULL && count >= 1)
	{
		count > 1 ? count = 2 : count;
		while (i != count - 1)
		{
			tmp[i] = tmp[i - count];
			i--;
		}
		if (count == 1)
			tmp = ft_strjoin_free("0", tmp, 2);
		else
			tmp[0] = '0';
		tmp[1] = 'x';
	}
	else if (tmp[0] != '\0')
		tmp = ft_strjoin_free("0x", tmp, 2);
	if (fmt[flg->i] == 'X')
		tmp = ft_str_toupper(tmp);
	return (tmp);
}

char		*ft_hash_oxx(char *tmp, t_flg *flg, const char *fmt)
{
	size_t	i;

	i = 0;
	if (fmt[flg->i] == 'o')
	{
		if (tmp[0] != '0' && tmp[0] != ' ')
			tmp = ft_strjoin_free("0", tmp, 2);
		else
		{
			while (tmp[i] == ' ')
				i++;
			if (tmp[i] != '0')
			{
				if (tmp[i] == '\0' && ft_strchr(flg->tab, '-') != NULL)
					tmp[0] = '0';
				else
					tmp[i - 1] = '0';
			}
		}
	}
	else if (fmt[flg->i] == 'x' || fmt[flg->i] == 'X')
		if (ft_strcmp(tmp, "0") != 0)
			return (ft_xx(tmp, flg, fmt, i));
	return (tmp);
}
