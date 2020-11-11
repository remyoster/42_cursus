/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:10:38 by roster            #+#    #+#             */
/*   Updated: 2020/04/17 10:38:28 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Free the list by passing it node to the del function and freeing the pointer
*/

void	ft_lstdel(t_list **alst, void (*del)(void *))
{
	t_list *tmp;

	if (!*alst)
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		del((*alst)->content);
		free(*alst);
		*alst = tmp;
	}
	*alst = NULL;
}
