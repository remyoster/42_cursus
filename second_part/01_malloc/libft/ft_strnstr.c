/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:28:46 by roster            #+#    #+#             */
/*   Updated: 2018/11/19 18:04:14 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			k = i;
			while (haystack[i] == needle[j] && i < len && haystack[i] != '\0')
			{
				i++;
				j++;
			}
			if (needle[j] == '\0')
				return ((char*)&haystack[k]);
			i = k;
		}
		i++;
	}
	return (0);
}
