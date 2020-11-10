/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 08:50:04 by roster            #+#    #+#             */
/*   Updated: 2018/12/18 09:17:12 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **lst)
{
	t_list	*before;
	t_list	*current;
	t_list	*after;

	before = NULL;
	current = *lst;
	while (current != NULL)
	{
		after = current->next;
		current->next = before;
		before = current;
		current = after;
	}
	*lst = before;
}
