/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 09:56:45 by roster            #+#    #+#             */
/*   Updated: 2020/03/13 07:59:26 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Create a new t_list struct
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *elem;

	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		if (!(elem->content = (void*)malloc(sizeof(void) * content_size)))
		{
			free(elem);
			return (NULL);
		}
		elem->content = ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
