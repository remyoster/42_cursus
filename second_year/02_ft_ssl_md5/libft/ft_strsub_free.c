/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 06:50:44 by roster            #+#    #+#             */
/*   Updated: 2019/03/05 06:52:22 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub_free(char *s, unsigned int start, size_t len, size_t mod)
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
	if (mod == 1)
		ft_strdel(&s);
	return (tronc);
}
