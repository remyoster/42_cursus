/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:55:39 by roster            #+#    #+#             */
/*   Updated: 2018/11/22 13:24:31 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b, size_t size)
{
	size_t	tmp[size];

	ft_memcpy(tmp, b, size);
	ft_memcpy(b, a, size);
	ft_memcpy(a, tmp, size);
}
