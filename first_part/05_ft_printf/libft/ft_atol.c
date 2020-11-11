/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:16:59 by roster            #+#    #+#             */
/*   Updated: 2019/03/12 08:03:46 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

long int	ft_atol(const char *str)
{
	size_t		i;
	long int	sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
		i++;
	if (i > 0 && str[i - 1] == 45)
		sign = -1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (long int)(str[i] - 48);
		i++;
	}
	return (res * sign);
}
