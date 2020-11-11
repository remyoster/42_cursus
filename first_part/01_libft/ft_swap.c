/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:55:39 by roster            #+#    #+#             */
/*   Updated: 2018/12/21 07:40:01 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
