/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:15:19 by roster            #+#    #+#             */
/*   Updated: 2019/02/27 09:17:41 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_fill_str(size_t div, long int n, char *str)
{
	size_t				i;
	unsigned long int	nb;

	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		nb = -n;
	}
	else
		nb = n;
	while (div >= 1)
	{
		str[i] = nb / div + 48;
		i++;
		nb = nb % div;
		div = div / 10;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(long int n)
{
	size_t				size_str;
	size_t				div;
	char				*str;
	unsigned long int	nb;

	size_str = 1;
	div = 1;
	if (n < 0)
	{
		size_str++;
		nb = -n;
	}
	else
		nb = n;
	while (nb / 10 >= 1)
	{
		size_str++;
		div = 10 * div;
		nb = nb / 10;
	}
	if (!(str = (char*)malloc(sizeof(char) * size_str + 1)))
		return (0);
	return (ft_fill_str(div, n, str));
}
