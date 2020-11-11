/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lh_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 08:36:32 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 09:36:06 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_l_flag(va_list ap, const char *fmt, t_flg *flg)
{
	flg->i++;
	if (fmt[flg->i + 1] == 'l')
		flg->i++;
	flg->tab[flg->k++] = fmt[flg->i];
	if (ft_parse_diouxx(fmt, flg, 0) != 0)
		return (ft_diouxx(ap, fmt, flg));
	else if (fmt[flg->i + 1] == 'f')
		return (ft_float(ap, fmt[flg->i + 1], flg));
	else
		return (ft_printf_error(ap, flg));
}

static char	*ft_h_flag(va_list ap, const char *fmt, t_flg *flg)
{
	flg->i++;
	if (fmt[flg->i + 1] == 'h')
		flg->i++;
	flg->tab[flg->k++] = fmt[flg->i];
	if (ft_parse_diouxx(fmt, flg, 0) != 0)
		return (ft_diouxx(ap, fmt, flg));
	else
		return (ft_printf_error(ap, flg));
}

char		*ft_lh_flags(va_list ap, const char *fmt, t_flg *flg)
{
	if (fmt[flg->i + 1] == 'l')
		return (ft_l_flag(ap, fmt, flg));
	else if (fmt[flg->i + 1] == 'h')
		return (ft_h_flag(ap, fmt, flg));
	else if (fmt[flg->i + 1] == 'L')
	{
		if (fmt[flg->i + 2] == 'f')
		{
			flg->tab[flg->k++] = fmt[flg->i + 1];
			return (ft_float(ap, fmt[flg->i + 1], flg));
		}
		else
			return (ft_printf_error(ap, flg));
	}
	else
		return (ft_printf_error(ap, flg));
}
