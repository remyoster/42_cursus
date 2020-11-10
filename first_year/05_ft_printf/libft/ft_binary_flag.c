/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:08:30 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 15:50:54 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_deal_brace(va_list ap, const char *fmt, t_flg *flg, int nb)
{
	int		base;
	size_t	i;
	char	*tmp;

	i = flg->i + 2;
	while (fmt[i] >= 48 && fmt[i] <= 57)
		i++;
	base = ft_atoi(&fmt[flg->i + 2]);
	if (base < 2 || base > 35 || fmt[i] != '}')
		return (ft_printf_error(ap, flg));
	tmp = ft_itoa_base(nb, base);
	flg->i = i;
	return (tmp);
}

char		*ft_binary_flag(va_list ap, const char *fmt, t_flg *flg)
{
	int		nb;

	flg->i++;
	nb = va_arg(ap, int);
	if (fmt[flg->i + 1] == '{')
		return (ft_deal_brace(ap, fmt, flg, nb));
	else
		return (ft_itoa_base(nb, 2));
}

char		*ft_bin_to_nb(va_list ap, const char *fmt, t_flg *flg)
{
	char	*tmp;
	char	*bin;

	if (fmt[flg->i + 2] != 'b')
		return (ft_printf_error(ap, flg));
	flg->i = flg->i + 2;
	bin = va_arg(ap, char *);
	if (bin == NULL)
		tmp = ft_strdup("(null)");
	else
		tmp = ft_str_binary_to_nb(bin, 0);
	if (!tmp)
		return (ft_printf_error(ap, flg));
	return (tmp);
}
