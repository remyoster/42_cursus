/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 07:08:09 by roster            #+#    #+#             */
/*   Updated: 2019/01/10 07:47:22 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strnchr_count(char *str, int c, size_t index, size_t len)
{
	size_t res;
	size_t count;

	res = 0;
	count = 0;
	while (count < len)
	{
		if (str[index] == c)
			res++;
		count++;
		index++;
	}
	return (res);
}
