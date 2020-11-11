/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:49:48 by roster            #+#    #+#             */
/*   Updated: 2020/03/13 07:57:53 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SWAP FIRST AND SECOND NODE OF A GIVEN LIST
** DOES NOTHING IF EMPTY LIST OR SINGLE NODE
*/
#include "libft.h"

void	ft_lstswap(t_list **alst)
{
	t_list *tmp;
	t_list *node1;

	if (!(*alst) || !((*alst)->next))
		return ;
	node1 = (*alst)->next;
	tmp = node1;
	(*alst)->next = tmp->next;
	tmp->next = *alst;
	*alst = node1;
}
