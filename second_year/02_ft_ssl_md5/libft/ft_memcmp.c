/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:13:21 by roster            #+#    #+#             */
/*   Updated: 2020/03/13 08:07:21 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** Compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*ps1;
	unsigned const char	*ps2;

	i = 0;
	ps1 = s1;
	ps2 = s2;
	if (n == 0)
		return (0);
	while (ps1[i] == ps2[i] && i < n - 1)
		i++;
	return (ps1[i] - ps2[i]);
}
