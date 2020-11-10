/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:00:35 by roster            #+#    #+#             */
/*   Updated: 2019/02/05 16:51:34 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_tabdel(void ***tab, size_t i, size_t j)
{
	size_t	x;
	size_t	y;
	void	**tmp;

	if (tab == NULL || *tab == NULL || **tab == NULL)
		return ;
	tmp = *tab;
	x = 0;
	while (x < i)
	{
		y = 0;
		while (y < j)
		{
			ft_memdel(&tmp[x][y]);
			y++;
		}
		x++;
	}
	free(*tab);
	*tab = NULL;
}
