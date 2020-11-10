/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:15:17 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 12:35:29 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_deal_p(va_list ap)
{
	char				*s;
	unsigned long int	addr;

	addr = va_arg(ap, unsigned long int);
	s = ft_itoa_printf(addr, 16, 64);
	s = ft_strjoin_free("0x", s, 2);
	return (s);
}

char		*ft_csp(va_list ap, const char *fmt, t_flg *flg)
{
	char	c;
	char	*s;

	flg->i++;
	flg->tab[flg->k++] = fmt[flg->i];
	if (fmt[flg->i] == 'c')
	{
		c = va_arg(ap, int);
		if (c == 0)
			flg->tab[flg->k++] = '@';
		s = ft_strnew(1);
		s[0] = c;
		return (s);
	}
	else if (fmt[flg->i] == 's')
	{
		s = va_arg(ap, char *);
		if (s == NULL)
			s = "(null)";
		return (ft_strdup(s));
	}
	else
		return (ft_deal_p(ap));
}
