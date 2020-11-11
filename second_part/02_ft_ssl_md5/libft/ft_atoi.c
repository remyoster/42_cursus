/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:53:18 by roster            #+#    #+#             */
/*   Updated: 2020/03/13 07:24:59 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Return an int val from a (number) string or 0
*/

int		ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
		i++;
	if (str[i - 1] == 45)
		sign = -1;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}
