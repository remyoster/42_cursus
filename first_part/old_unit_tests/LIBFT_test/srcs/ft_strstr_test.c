/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:20:43 by roster            #+#    #+#             */
/*   Updated: 2018/11/19 17:49:01 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strstr_test(void)
{
	char *name = "FT_STRSTR";
	char *(*pt)(const char *, const char *);
	int i;
	int j;
	const char haystack[5][20] = {"MZIRIBMZIRIBMZP", "La rosterlinette", "La rosterlinette", "", "ooooui"};
	const char needle[5][20] = {"MZIRIBMZP", "", "La rosterlinette", "", "nom"};

	print_begin(name);
	pt = ft_strstr;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (strcmp(pt(haystack[i], needle[i]), strstr(haystack[i], needle[i])) == 0)
			print_ok(i + 1);
		else
		{
			print_wrong_char(pt(haystack[i], needle[i]), strstr(haystack[i], needle[i]), (i + 1));
			j++;
		}
		i++;
	}
	if (pt(haystack[i], needle[i]) == NULL && strstr(haystack[i], needle[i]) == NULL)
		print_ok(i + 1);
	else
	{
		print_wrong_char(pt(haystack[i], needle[i]), strstr(haystack[i], needle[i]), (i + 1));
		j++;
	}
	print_end(j);
	return (j);
}
