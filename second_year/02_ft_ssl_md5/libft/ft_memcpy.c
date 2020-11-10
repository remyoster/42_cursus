/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:33:39 by roster            #+#    #+#             */
/*   Updated: 2020/03/13 07:40:40 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Copy memory area from memory area src to memory area dst
** Carefull with n, if it's too big it will cause bus error
** If n i too small nothing happened
*/

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*pdst;
	const char	*psrc;

	i = 0;
	pdst = dst;
	psrc = src;
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}
