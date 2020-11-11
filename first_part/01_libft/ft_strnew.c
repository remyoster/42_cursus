/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 07:34:51 by roster            #+#    #+#             */
/*   Updated: 2018/11/20 09:18:01 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (0);
	ft_memset(str, 0, size + 1);
	i = 0;
	while (i < size + 1)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
