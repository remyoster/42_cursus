/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 08:57:44 by roster            #+#    #+#             */
/*   Updated: 2019/02/27 09:09:05 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_fill_str(size_t div, unsigned long int n, char *str)
{
	size_t	i;

	i = 0;
	while (div >= 1)
	{
		str[i] = n / div + 48;
		i++;
		n = n % div;
		div = div / 10;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_uitoa(unsigned long int n)
{
	size_t				size_str;
	size_t				div;
	char				*str;
	unsigned long int	nb;

	nb = n;
	size_str = 1;
	div = 1;
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
