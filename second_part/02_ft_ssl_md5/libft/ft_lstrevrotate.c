/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrevrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 07:15:23 by roster            #+#    #+#             */
/*   Updated: 2019/10/10 07:16:01 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SHIFT EVERY LINK DOWNWARDS SO THAT THE LAST LINK BECOME THE FIRST
*/

#include "libft.h"

void	ft_lstrevrotate(t_list **alst)
{
	t_list	*prev;
	t_list	*tmp;

	if (!(*alst) || !((*alst)->next))
		return ;
	prev = *alst;
	tmp = (*alst)->next;
	while (tmp->next != NULL)
	{
		prev = prev->next;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = (*alst);
	*alst = tmp;
}
