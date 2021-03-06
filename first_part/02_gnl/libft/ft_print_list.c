/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:23:30 by roster            #+#    #+#             */
/*   Updated: 2018/11/28 12:12:12 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		ft_putstr(lst->content);
		ft_putstr("->");
		lst = lst->next;
	}
}
