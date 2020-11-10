/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:35:19 by roster            #+#    #+#             */
/*   Updated: 2019/03/07 12:53:56 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_hexa_base(char *bin)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	res;

	str = ft_strnew(16);
	i = 0;
	j = 0;
	res = 0;
	while (bin[i])
	{
		if (bin[i] == '1')
			res = res + ft_power(2, (i % 4));
		if ((i + 1) % 4 == 0)
		{
			res >= 10 ? res = res + 39 : res;
			str[j++] = res + 48;
			res = 0;
		}
		i++;
	}
	res != 0 ? str[j] = res + 48 : str[j];
	ft_strdel(&bin);
	ft_strrev(&str);
	return (str);
}

static char	*ft_octal_base(char *bin)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	res;

	str = ft_strnew(22);
	i = 0;
	j = 0;
	res = 0;
	while (bin[i])
	{
		if (bin[i] == '1')
			res = res + ft_power(2, (i % 3));
		if ((i + 1) % 3 == 0)
		{
			str[j++] = res + 48;
			res = 0;
		}
		i++;
	}
	if (res != 0)
		str[j] = res + 48;
	ft_strdel(&bin);
	ft_strrev(&str);
	return (str);
}

char		*ft_itoa_printf(long int nb, int base, size_t mod)
{
	char		*bin;
	size_t		i;

	bin = ft_strnew(64);
	if (nb == 0)
	{
		bin[0] = '0';
		return (bin);
	}
	i = 0;
	while (nb && i < mod)
	{
		if (nb & 1)
			bin[i] = '1';
		else
			bin[i] = '0';
		i++;
		nb >>= 1;
	}
	if (base != 2)
		return (base == 8 ? ft_octal_base(bin) : ft_hexa_base(bin));
	ft_strrev(&bin);
	return (bin);
}
