/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:58:53 by roster            #+#    #+#             */
/*   Updated: 2020/03/13 07:43:54 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Count nodes in a t_list
*/

size_t	ft_lstcount(t_list **lst)
{
	t_list	*tmp;
	size_t	count;

	if (!(*lst))
		return (0);
	tmp = *lst;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
