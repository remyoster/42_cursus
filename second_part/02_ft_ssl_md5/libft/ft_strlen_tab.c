/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:30:20 by roster            #+#    #+#             */
/*   Updated: 2019/10/08 15:04:50 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Return the size of an array of string
*/

#include <string.h>

size_t	ft_strlen_tab(const char **s)
{
	size_t	i;

	if (!(*s))
		return (0);
	i = 0;
	while (*(s + i))
		i++;
	return (i);
}
