/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:21:03 by roster            #+#    #+#             */
/*   Updated: 2018/11/22 13:52:10 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	i = 0;
	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	c = (unsigned char)c;
	while (i < n)
	{
		pdst[i] = psrc[i];
		if (psrc[i] == c)
			return (&pdst[i + 1]);
		i++;
	}
	return (NULL);
}
