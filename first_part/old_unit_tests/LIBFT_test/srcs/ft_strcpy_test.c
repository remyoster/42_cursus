/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:37:29 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:14:41 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strcpy_test(void)
{
	char *name = "FT_STRCPY";
	char *(*pt)(char *, const char *);
	int i;
	int j;
	char  dst[4][20] = {"aa", "La rosterlinette", "La rosterlinette", ""};
	char const src[4][20] = {"aaaaaaa", "est magique", "La rosterlinette", ""};

	print_begin(name);
	pt = ft_strcpy;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (strcmp(pt(dst[i], src[i]), strcpy(dst[i], src[i])) == 0)
			print_ok(i + 1);
		else
		{
			print_wrong_char(pt(dst[i], src[i]), strcpy(dst[i],src[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
