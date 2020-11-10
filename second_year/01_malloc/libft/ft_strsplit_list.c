/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 09:31:49 by roster            #+#    #+#             */
/*   Updated: 2018/11/22 10:45:53 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_strsplit_list(char const *s, char c)
{
	char	**tab;
	t_list	*begin;
	t_list	*elem;
	size_t	i;

	if (!s)
		return (NULL);
	tab = ft_strsplit(s, c);
	elem = ft_lstnew(tab[0], ft_strlen(tab[0]));
	begin = elem;
	i = 1;
	while (tab[i])
	{
		elem->next = ft_lstnew(tab[i], ft_strlen(tab[i]));
		elem = elem->next;
		i++;
	}
	return (begin);
}
