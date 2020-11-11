/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:03:31 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 09:41:12 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_next_flags(va_list ap, const char *fmt, t_flg *flg, char **tmp)
{
	if (fmt[flg->i + 1] == '.')
		*tmp = ft_accuracy(ap, fmt, flg);
	else if (fmt[flg->i + 1] == 'b')
		*tmp = ft_binary_flag(ap, fmt, flg);
	else if (fmt[flg->i + 1] == '~')
		*tmp = ft_bin_to_nb(ap, fmt, flg);
	else
		return (ft_printf_error(ap, flg));
	return (*tmp);
}

char		*ft_dispatcher(va_list ap, const char *fmt, t_flg *flg)
{
	char	*tmp;

	if (ft_parse_csp(fmt, flg, 0) != 0)
		tmp = ft_csp(ap, fmt, flg);
	else if (ft_parse_diouxx(fmt, flg, 0) != 0)
		tmp = ft_diouxx(ap, fmt, flg);
	else if (ft_parse_lh(fmt, flg, 0) != 0)
		tmp = ft_lh_flags(ap, fmt, flg);
	else if (fmt[flg->i + 1] == 'f')
		tmp = ft_float(ap, fmt[flg->i + 1], flg);
	else if (fmt[flg->i + 1] == '%')
		tmp = ft_percent(flg);
	else if (fmt[flg->i + 1] == '+')
		tmp = ft_plus_flag(ap, fmt, flg);
	else if (fmt[flg->i + 1] == '-')
		tmp = ft_minus_flag(ap, fmt, flg);
	else if (fmt[flg->i + 1] == ' ')
		tmp = ft_space_flag(ap, fmt, flg);
	else if (fmt[flg->i + 1] == '#')
		tmp = ft_hashtag(ap, fmt, flg);
	else if (fmt[flg->i + 1] >= 48 && fmt[flg->i + 1] <= 57)
		tmp = ft_number_flag(ap, fmt, flg);
	else
		return (ft_next_flags(ap, fmt, flg, &tmp));
	return (tmp);
}
