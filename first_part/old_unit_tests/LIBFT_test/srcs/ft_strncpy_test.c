/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:03:09 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:49:55 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strncpy_test(void)
{
	char *name = "FT_STRNCPY";
	char *(*pt)(char *, const char *, size_t);
	int i;
	int j;
	char  dst[4][20] = {"", "La rosterlinette", "La rosterlinette", ""};
	char const src[4][20] = {"aaaaaaa", "est magique", "La rosterlinette", ""};
	size_t len[4] = {3, 16, 8, 0}; 

	print_begin(name);
	pt = ft_strncpy;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (strcmp(pt(dst[i], src[i], len[i]), strncpy(dst[i], src[i], len[i])) == 0)
			print_ok(i + 1);
		else
		{
			print_wrong_char(pt(dst[i], src[i], len[i]), strncpy(dst[i],src[i], len[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
