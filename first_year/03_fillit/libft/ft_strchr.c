/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:29:36 by roster            #+#    #+#             */
/*   Updated: 2018/11/22 13:55:34 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	x;

	i = 0;
	str = (char*)s;
	x = (char)c;
	while (s[i] != '\0')
	{
		if (str[i] == x)
			return (&str[i]);
		i++;
	}
	if (x == 0)
		return (&str[i]);
	return (NULL);
}
