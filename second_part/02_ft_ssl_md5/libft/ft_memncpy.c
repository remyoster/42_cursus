/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 11:53:43 by roster            #+#    #+#             */
/*   Updated: 2020/04/22 13:25:17 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Copy memory area from memory area src to memory area dst from start index
** Carefull with n and start, if it's too big it will cause bus error
** If n i too small nothing happened
*/

#include <string.h>

void	*ft_memncpy(void *dst, const void *src, size_t start, size_t n)
{
	size_t		i;
	char		*pdst;
	const char	*psrc;

	i = 0;
	pdst = dst;
	psrc = src;
	while (i < n)
	{
		pdst[start] = psrc[i];
		i++;
		start++;
	}
	return (dst);
}
