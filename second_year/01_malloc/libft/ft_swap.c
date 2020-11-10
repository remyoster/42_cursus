/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:55:39 by roster            #+#    #+#             */
/*   Updated: 2019/10/08 09:33:56 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Swap two memory area by using ft_memcpy to rewrite
** Carefull with size, if it's too big ft_memcpy will crash, if it's too small
** ft_memcpy does nothing, either the swap
*/

#include "libft.h"
#include <stdlib.h>

void	ft_swap(void *a, void *b, size_t size)
{
	size_t	*tmp;

	if (!(tmp = (size_t*)malloc(sizeof(size_t) * size + 1)))
		return ;
	ft_memcpy(tmp, b, size);
	ft_memcpy(b, a, size);
	ft_memcpy(a, tmp, size);
	free(tmp);
	tmp = NULL;
}
