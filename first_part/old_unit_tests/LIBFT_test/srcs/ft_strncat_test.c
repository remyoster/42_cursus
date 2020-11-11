/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:15:49 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:17:11 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strncat_test(void)
{
	char *name = "FT_STRNCAT";
	char *(*pt)(char *, const char *, size_t);
	int i;
	int j;
	char  s1[4][20] = {"aaaaaaaaaa", "La rosterlinette", "La rosterlinette", ""};
	char const s2[4][20] = {"aaaaaaa", "est magique", "La rosterlinette", ""};
	size_t n[4] = {5, 10, 0, 1};

	print_begin(name);
	pt = ft_strncat;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (strcmp(pt(s1[i], s2[i], n[i]), strncat(s1[i], s2[i], n[i])) == 0)
			print_ok(i + 1);
		else
		{
			print_wrong_char(pt(s1[i], s2[i], n[i]), strncat(s1[i],s2[i], n[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
