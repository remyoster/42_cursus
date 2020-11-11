/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diouxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:56:50 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 15:43:00 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_di_conv(va_list ap, const char *fmt, t_flg *flg)
{
	int				d;
	long int		ld;
	char			*s;

	if (fmt[flg->i - 1] != 'l')
	{
		d = va_arg(ap, int);
		if (fmt[flg->i - 2] == 'h')
			s = ft_itoa((char)d);
		else if (fmt[flg->i - 2] != 'h' && fmt[flg->i - 1] == 'h')
			s = ft_itoa((short int)d);
		else
			s = ft_itoa(d);
	}
	else
	{
		ld = va_arg(ap, long int);
		s = ft_itoa(ld);
	}
	return (s);
}

static char	*ft_o_conv(va_list ap, const char *fmt, t_flg *flg)
{
	int				d;
	long int		ld;
	char			*s;

	if (fmt[flg->i - 1] != 'l')
	{
		d = va_arg(ap, int);
		if (fmt[flg->i - 2] == 'h')
			s = ft_itoa_printf(d, 8, 8);
		else if (fmt[flg->i - 2] != 'h' && fmt[flg->i - 1] == 'h')
			s = ft_itoa_printf(d, 8, 16);
		else
			s = ft_itoa_printf(d, 8, 32);
	}
	else
	{
		ld = va_arg(ap, long int);
		s = ft_itoa_printf(ld, 8, 64);
	}
	return (s);
}

static char	*ft_x_conv(va_list ap, const char *fmt, t_flg *flg)
{
	int			d;
	char		*s;
	long int	ld;

	if (fmt[flg->i - 1] != 'l')
	{
		d = va_arg(ap, int);
		if (fmt[flg->i - 2] == 'h')
			s = ft_itoa_printf(d, 16, 8);
		else if (fmt[flg->i - 2] != 'h' && fmt[flg->i - 1] == 'h')
			s = ft_itoa_printf(d, 16, 16);
		else
			s = ft_itoa_printf(d, 16, 32);
	}
	else
	{
		ld = va_arg(ap, long int);
		s = ft_itoa_printf(ld, 16, 64);
	}
	if (fmt[flg->i] == 'X')
		s = ft_str_toupper(s);
	return (s);
}

static char	*ft_u_conv(va_list ap, const char *fmt, t_flg *flg)
{
	char				*tmp;
	unsigned int		ui;
	unsigned long int	uli;

	if (fmt[flg->i - 1] == 'l')
	{
		uli = va_arg(ap, unsigned long int);
		tmp = ft_uitoa(uli);
	}
	else
	{
		ui = va_arg(ap, unsigned int);
		tmp = ft_uitoa(ui);
	}
	return (tmp);
}

char		*ft_diouxx(va_list ap, const char *fmt, t_flg *flg)
{
	flg->i++;
	flg->tab[flg->k++] = fmt[flg->i];
	if (fmt[flg->i] == 'o')
		return (ft_o_conv(ap, fmt, flg));
	else if (fmt[flg->i] == 'u')
		return (ft_u_conv(ap, fmt, flg));
	else if (fmt[flg->i] == 'x' || fmt[flg->i] == 'X')
		return (ft_x_conv(ap, fmt, flg));
	else
		return (ft_di_conv(ap, fmt, flg));
}
