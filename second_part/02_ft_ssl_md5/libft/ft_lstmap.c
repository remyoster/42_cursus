/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:27:55 by roster            #+#    #+#             */
/*   Updated: 2020/03/13 08:00:18 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Return a new t_list chained by passing a function to a t_list given
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *tmp;
	t_list *elem;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	elem = ft_lstnew(tmp->content, tmp->content_size);
	begin = elem;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		elem->next = ft_lstnew(tmp->content, tmp->content_size);
		elem = elem->next;
		lst = lst->next;
	}
	return (begin);
}
