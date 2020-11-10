/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:27:55 by roster            #+#    #+#             */
/*   Updated: 2018/11/22 09:21:19 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
