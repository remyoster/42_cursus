/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 09:01:41 by roster            #+#    #+#             */
/*   Updated: 2020/03/13 08:09:41 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add a node at the beginning of a t_list
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!alst)
		return ;
	new->next = *alst;
	*alst = new;
}
