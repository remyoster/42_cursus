/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:02:02 by roster            #+#    #+#             */
/*   Updated: 2019/02/06 18:48:05 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_tabdel_char(char ***tab)
{
	size_t	i;
	char	**tmp;

	if (tab == NULL || *tab == NULL)
		return ;
	i = 0;
	tmp = *tab;
	while (tmp[i] != 0)
	{
		ft_strdel(&tmp[i]);
		i++;
	}
	free(*tab);
	*tab = NULL;
}
