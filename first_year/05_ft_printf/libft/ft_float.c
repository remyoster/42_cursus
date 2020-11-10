/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 13:39:47 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 09:32:09 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_round_str_next(char **s, size_t i)
{
	if ((*s)[i] == 58)
	{
		(*s)[i] = '0';
		i = i - 2;
		(*s)[i] = (*s)[i] + 1;
		while (i > 0 && (*s)[i] == 58)
		{
			(*s)[i] = '0';
			(*s)[i - 1] = (*s)[i - 1] + 1;
			i--;
		}
	}
	if (i == 0 && (*s)[i] == 58)
	{
		(*s)[i] = '0';
		*s = ft_strjoin_free("1", *s, 2);
	}
	*s = ft_strsub_free(*s, 0, ft_strlen(*s) - 1, 1);
}

static void	ft_round_str(char **s)
{
	size_t	i;

	i = ft_strlen(*s) - 1;
	if ((*s)[i] >= '5')
		(*s)[i - 1] = (*s)[i - 1] + 1;
	while ((*s)[i - 1] != '.' && (*s)[i - 1] == 58)
	{
		(*s)[i - 1] = '0';
		(*s)[i - 2] = (*s)[i - 2] + 1;
		i--;
	}
	ft_round_str_next(s, i);
}

static char	*ft_fill_zero(char *tmp, t_flg *flg, size_t len)
{
	char	*zero_str;

	zero_str = ft_strnew(flg->acc - len);
	ft_memset(zero_str, '0', flg->acc - len);
	tmp = ft_strjoin_free(tmp, zero_str, 0);
	return (tmp);
}

static char	*ft_deal_float(char *tmp, t_flg *flg)
{
	size_t i;
	size_t len;

	len = ft_strlen(tmp);
	i = 0;
	while (tmp[i] != '.')
		i++;
	if (flg->acc == 0)
	{
		if (tmp[i + 1] >= '5' && tmp[i + 2] != '\0')
			tmp = ft_add_str(ft_strsub_free(tmp, 0, i, 1), "1", 1);
		else
			tmp = ft_strsub_free(tmp, 0, i, 1);
		return (tmp);
	}
	if (flg->acc + i + 2 < len)
		tmp = ft_strsub_free(tmp, 0, flg->acc + i + 2, 1);
	len = ft_strlen(tmp) - i - 1;
	if (len > flg->acc)
		ft_round_str(&tmp);
	else
		tmp = ft_fill_zero(tmp, flg, len);
	return (tmp);
}

char		*ft_float(va_list ap, char flag, t_flg *flg)
{
	double		d;
	long double	ld;
	char		*tmp;

	flg->i++;
	if (flag == 'f')
	{
		d = va_arg(ap, double);
		tmp = ft_dtoa(d);
	}
	else if (flag == 'L')
	{
		flg->i++;
		ld = va_arg(ap, long double);
		tmp = ft_ldtoa(ld);
	}
	else
		return (ft_printf_error(ap, flg));
	if (ft_strcmp("nan", tmp) == 0 || tmp[0] == 'i' || tmp[1] == 'i')
		return (tmp);
	return (ft_deal_float(tmp, flg));
}
