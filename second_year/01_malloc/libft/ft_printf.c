/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:16:35 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 14:34:50 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	ft_deal_buff(char const *fmt, t_flg *flg)
{
	if (ft_strlen(flg->buff) < 4095)
		ft_strncat(flg->buff, &fmt[flg->i], 1);
	else
	{
		ft_putstr(flg->buff);
		flg->count = flg->count + 4095;
		ft_strclr(flg->buff);
		ft_strncat(flg->buff, &fmt[flg->i], 1);
	}
}

static void	ft_set_data(t_flg *flg)
{
	flg->i = 0;
	flg->k = 0;
	flg->count = 0;
	flg->acc = 6;
	ft_memset(flg->tab, '\0', 30);
	ft_memset(flg->buff, '\0', 4096);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_flg	flg;
	char	*buff;

	if (!fmt)
		return (-1);
	ft_set_data(&flg);
	va_start(ap, fmt);
	while (fmt[flg.i])
	{
		if (fmt[flg.i] == '%')
		{
			buff = ft_dispatcher(ap, fmt, &flg);
			if (ft_putstr_printf(buff, &flg) == -1)
				return (-1);
		}
		else
			ft_deal_buff(fmt, &flg);
		flg.i++;
	}
	ft_putstr(flg.buff);
	flg.count = flg.count + ft_strlen(flg.buff);
	va_end(ap);
	return ((int)flg.count);
}
