/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:15:19 by roster            #+#    #+#             */
/*   Updated: 2018/11/22 14:08:29 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*ft_fill_str(int div, int n, char *str)
{
	size_t	i;
	long	nb;

	nb = n;
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		nb = -nb;
	}
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

char			*ft_itoa(int n)
{
	size_t	size_str;
	size_t	div;
	char	*str;
	long	nb;

	nb = n;
	size_str = 1;
	div = 1;
	if (n < 0)
	{
		size_str++;
		nb = -nb;
	}
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
