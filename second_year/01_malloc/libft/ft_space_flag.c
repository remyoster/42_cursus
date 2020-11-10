/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:15:21 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 14:26:09 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_deal_zero(char *tmp)
{
	size_t i;

	i = 0;
	if (ft_strlen(tmp) > 1)
	{
		if (ft_strchr(tmp, '.') != NULL)
		{
			if (tmp[1] != '.')
				tmp[0] = ' ';
		}
		else if (ft_strchr(tmp, ' ') != NULL)
		{
			i = ft_strlen(tmp) - 1;
			while (i != 0)
			{
				tmp[i] = tmp[i - 1];
				i--;
			}
			tmp[0] = ' ';
		}
	}
	return (tmp);
}

char		*ft_space_flag(va_list ap, const char *fmt, t_flg *flg)
{
	char	*tmp;

	flg->tab[flg->k++] = ' ';
	while (fmt[flg->i + 1] == ' ')
		flg->i++;
	tmp = ft_dispatcher(ap, fmt, flg);
	if (fmt[flg->i] == 'd' || fmt[flg->i] == 'i' || fmt[flg->i] == 'f')
	{
		if (tmp[0] == '0')
			tmp = ft_deal_zero(tmp);
		if (tmp[0] != ' ' && tmp[0] != '+' && tmp[0] != '-')
			tmp = ft_strjoin_free(" ", tmp, 2);
	}
	return (tmp);
}
