/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:32:07 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 14:52:51 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_strrev(char **str)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = ft_strlen(*str);
	j = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * i + 1)))
		exit(1);
	i--;
	while (i != 0)
		tmp[j++] = (*str)[i--];
	tmp[j] = *str[i];
	tmp[j + 1] = '\0';
	ft_strcpy(*str, tmp);
	ft_strdel(&tmp);
}
