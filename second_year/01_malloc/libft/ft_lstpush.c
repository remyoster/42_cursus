/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:58:03 by roster            #+#    #+#             */
/*   Updated: 2019/10/09 11:02:10 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ADD A NODE AT THE END OF THE LIST
*/

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (!(alst) || !(*alst))
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
