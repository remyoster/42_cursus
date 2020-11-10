/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:32:15 by roster            #+#    #+#             */
/*   Updated: 2018/11/22 15:05:53 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_sort_tab(int *tab, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[j] > tab[j + 1] && j + 1 < size)
				ft_swap(&tab[j], &tab[j + 1], sizeof(int));
			j++;
		}
		i++;
	}
	return (tab);
}
