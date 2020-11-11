/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:30:16 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 15:05:23 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strcat_test(void)
{
	char *name = "FT_STRCAT";
	char *(*pt)(char *, const char *);
	int i;
	int j;
	char s1[4][20] = {"aa", "La rosterlinette", "La rosterlinette", ""};
	char const s2[4][20] = {"aaaaaaaaaaaa", "est magique", "La rosterlinette", ""};

	print_begin(name);
	pt = ft_strcat;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (strcmp(pt(s1[i], s2[i]), strcat(s1[i], s2[i])) == 0)
			print_ok(i + 1);
		else
		{
			print_wrong_char(pt(s1[i], s2[i]), strcat(s1[i],s2[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
