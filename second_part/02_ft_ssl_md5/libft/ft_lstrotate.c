/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 07:12:29 by roster            #+#    #+#             */
/*   Updated: 2019/10/10 07:15:12 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SHIFT EVERY LINK UPWARDS SO THAT THE FIRST LINK BECOME THE LAST
*/

#include "libft.h"

void	ft_lstrotate(t_list **alst)
{
	t_list	*end;
	t_list	*tmp;

	if (!(*alst) || !((*alst)->next))
		return ;
	tmp = *alst;
	*alst = (*alst)->next;
	end = *alst;
	while (end->next != NULL)
		end = end->next;
	end->next = tmp;
	tmp->next = NULL;
}
