/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:22:23 by roster            #+#    #+#             */
/*   Updated: 2020/03/13 07:56:56 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Call a f function on every node of a t_list
*/

void	ft_lstiter(t_list *list, void (*f)(t_list *elem))
{
	if (!list)
		return ;
	while (list)
	{
		f(list);
		list = list->next;
	}
}
