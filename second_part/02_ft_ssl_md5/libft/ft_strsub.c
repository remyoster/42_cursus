/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:50:24 by roster            #+#    #+#             */
/*   Updated: 2018/11/20 16:06:27 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tronc;

	if (!s)
		return (NULL);
	i = 0;
	if (!(tronc = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	while (i < len)
	{
		tronc[i] = s[start];
		i++;
		start++;
	}
	tronc[i] = '\0';
	return (tronc);
}
