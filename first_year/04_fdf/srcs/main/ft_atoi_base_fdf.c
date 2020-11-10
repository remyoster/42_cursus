/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_fdf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:14:41 by roster            #+#    #+#             */
/*   Updated: 2019/02/11 19:10:27 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int		ft_atoi_base_fdf(char *str)
{
	int		res;
	size_t	i;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			res = res + (str[i] - 48) * ft_power(16, (5 - i));
		else if (str[i] >= 65 && str[i] <= 70)
			res = res + (str[i] - 55) * ft_power(16, (5 - i));
		else
			res = res + (str[i] - 87) * ft_power(16, (5 - i));
		i++;
	}
	return (res);
}
