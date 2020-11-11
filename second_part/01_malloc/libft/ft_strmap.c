/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:39:48 by roster            #+#    #+#             */
/*   Updated: 2018/11/23 13:40:35 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
