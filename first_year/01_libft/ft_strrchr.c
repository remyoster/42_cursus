/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:24:33 by roster            #+#    #+#             */
/*   Updated: 2018/11/22 15:35:15 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	x;

	str = (char*)s;
	x = (char)c;
	i = ft_strlen(s);
	while (i > -1)
	{
		if (s[i] == c)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
