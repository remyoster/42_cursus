/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:36:35 by roster            #+#    #+#             */
/*   Updated: 2019/10/08 15:04:23 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check if the string passed in arguments is a number or not
*/

#include "libft.h"

int	ft_isnumber(char *num)
{
	size_t	i;

	if (!num)
		return (0);
	i = 0;
	if (num[i] == '-')
		i++;
	while (ft_isdigit(num[i]))
		i++;
	if (i != ft_strlen(num))
		return (0);
	return (1);
}
