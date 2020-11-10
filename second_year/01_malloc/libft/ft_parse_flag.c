/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 08:08:48 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 14:32:36 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_csp(const char *fmt, t_flg *flg, int mod)
{
	int	bol;

	bol = 0;
	flg->i = flg->i + mod;
	if (fmt[flg->i + 1] == 'c' || fmt[flg->i + 1] == 's'
			|| fmt[flg->i + 1] == 'p')
		bol = fmt[flg->i + 1];
	flg->i = flg->i - mod;
	return (bol);
}

int		ft_parse_diouxx(const char *fmt, t_flg *flg, int mod)
{
	int	bol;

	bol = 0;
	flg->i = flg->i + mod;
	if (fmt[flg->i + 1] == 'd' || fmt[flg->i + 1] == 'i'
			|| fmt[flg->i + 1] == 'o' || fmt[flg->i + 1] == 'u'
			|| fmt[flg->i + 1] == 'x' || fmt[flg->i + 1] == 'X')
		bol = fmt[flg->i + 1];
	flg->i = flg->i - mod;
	return (bol);
}

int		ft_parse_lh(const char *fmt, t_flg *flg, int mod)
{
	int	bol;

	bol = 0;
	flg->i = flg->i + mod;
	if (fmt[flg->i + 1] == 'l' || fmt[flg->i + 1] == 'h'
			|| fmt[flg->i + 1] == 'L')
		bol = fmt[flg->i + 1];
	flg->i = flg->i - mod;
	return (bol);
}
