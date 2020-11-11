/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 07:29:00 by roster            #+#    #+#             */
/*   Updated: 2020/03/13 08:02:42 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Malloc and fill the memory with 0
*/

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = (void*)malloc(sizeof(size_t) * size)))
		return (NULL);
	mem = ft_memset(mem, 0, size);
	return (mem);
}
