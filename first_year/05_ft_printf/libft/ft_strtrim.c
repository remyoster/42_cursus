/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 08:49:15 by roster            #+#    #+#             */
/*   Updated: 2018/11/20 17:06:25 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_space(char const *s)
{
	size_t i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*trim;

	if (!s)
		return (NULL);
	i = ft_count_space(s);
	j = 0;
	k = ft_strlen(s);
	while (s[k - 1] == ' ' || s[k - 1] == '\n' || s[k - 1] == '\t')
		k--;
	if (k < i)
		i = 0;
	if (!(trim = (char*)malloc(sizeof(char) * (k - i) + 1)))
		return (0);
	while (i < k)
	{
		trim[j] = s[i];
		i++;
		j++;
	}
	trim[j] = '\0';
	return (trim);
}
