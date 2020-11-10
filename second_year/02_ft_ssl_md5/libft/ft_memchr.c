/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 12:19:55 by roster            #+#    #+#             */
/*   Updated: 2020/03/13 08:06:16 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** locate byte (c) in a byte string
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;
	unsigned char	x;

	i = 0;
	ps = (unsigned char*)s;
	x = (unsigned char)c;
	while (i < n)
	{
		if (ps[i] == x)
			return (&ps[i]);
		i++;
	}
	return (NULL);
}
