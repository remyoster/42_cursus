/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:06:28 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 11:16:12 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char		*ft_deal_space(char *tmp)
{
	size_t i;

	i = 0;
	while (tmp[i] == ' ')
		i++;
	if (tmp[i] >= 48 && tmp[i] <= 57)
		tmp[i - 1] = '+';
	return (tmp);
}

char		*ft_deal_minus(char *tmp)
{
	size_t i;

	i = ft_strlen(tmp) - 1;
	if (tmp[i] == ' ')
	{
		if (ft_strchr(tmp, '-') == NULL && ft_strchr(tmp, '+') == NULL)
		{
			while (i != 0)
			{
				tmp[i] = tmp[i - 1];
				i--;
			}
			tmp[i] = '+';
		}
	}
	else if (tmp[0] == ' ')
		return (ft_deal_space(tmp));
	else if (tmp[0] != '+' && tmp[0] != '-')
		tmp = ft_strjoin_free("+", tmp, 2);
	return (tmp);
}

char		*ft_deal_nb_inf(char *tmp, t_flg *flg)
{
	if (ft_strchr(flg->tab, '0') != NULL)
		if (tmp[0] == '0')
			if (ft_strlen(tmp) > 1 && tmp[1] != '.')
				tmp[0] = '+';
	if (tmp[0] != '+' && tmp[0] != '-')
		tmp = ft_strjoin_free("+", tmp, 2);
	return (tmp);
}

char		*ft_plus_flag(va_list ap, const char *fmt, t_flg *flg)
{
	char *tmp;

	flg->tab[flg->k++] = '+';
	while (fmt[flg->i + 1] == '+')
		flg->i++;
	tmp = ft_dispatcher(ap, fmt, flg);
	if (ft_parse_csp(fmt, flg, -1) != 0 || fmt[flg->i] == 'o'
			|| fmt[flg->i] == 'u' || fmt[flg->i] == 'x'
			|| fmt[flg->i] == 'X' || fmt[flg->i] == '%')
		return (tmp);
	if (ft_strchr(flg->tab, '-') != NULL)
		return (ft_deal_minus(tmp));
	else if (tmp[0] == ' ')
		return (ft_deal_space(tmp));
	else if ((tmp[0] >= 48 && tmp[0] <= 57) || ft_strcmp("inf", tmp) == 0)
		return (ft_deal_nb_inf(tmp, flg));
	else if (tmp[0] == 0 && ft_strchr(flg->tab, '.') != NULL)
		tmp = ft_strjoin_free("+", tmp, 2);
	return (tmp);
}
