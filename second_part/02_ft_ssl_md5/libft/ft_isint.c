/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:50:10 by roster            #+#    #+#             */
/*   Updated: 2019/10/08 15:14:11 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check is the string passed in params is a INT
*/

#include "libft.h"

int	ft_isint(char *str)
{
	long int	nb;
	size_t		len;

	if (!str || !ft_isnumber(str))
		return (0);
	len = ft_strlen(str);
	if ((str[0] == '-' && len > 11) || (str[0] != '-' && len > 10))
		return (0);
	else
	{
		nb = ft_atol(str);
		if (nb > 2147483647 || nb < -2147483648)
			return (0);
		else
			return (1);
	}
}
