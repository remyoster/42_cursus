/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstunlink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:30:16 by roster            #+#    #+#             */
/*   Updated: 2020/03/13 08:10:55 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DELETE A NODE WITHOUT BREAKING THE CHAIN BY FREEING CONTENT + NODE HIMSELF
*/

#include "libft.h"
#include <stdlib.h>

static void	del(t_list *node)
{
	free(node->content);
	free(node);
	node = NULL;
}

void		ft_lstunlink(t_list **alst, t_list *node)
{
	t_list	*tmp;
	t_list	*prev;

	if (!*alst)
		return ;
	prev = *alst;
	if (prev == node)
	{
		*alst = prev->next;
		return (del(prev));
	}
	while (prev)
	{
		tmp = prev->next;
		if (tmp == node)
		{
			prev->next = tmp->next;
			return (del(tmp));
		}
		prev = prev->next;
	}
}
