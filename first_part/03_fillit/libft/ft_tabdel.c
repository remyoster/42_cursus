/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:00:35 by roster            #+#    #+#             */
/*   Updated: 2019/01/10 14:33:36 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_tabdel(char **tab)
{
	size_t i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i] != 0)
	{
		if (tab[i])
			ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}
