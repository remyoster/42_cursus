/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:28:36 by roster            #+#    #+#             */
/*   Updated: 2020/03/13 07:40:44 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Fill a byte string (void *b) with a byte value (c)
*/

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
