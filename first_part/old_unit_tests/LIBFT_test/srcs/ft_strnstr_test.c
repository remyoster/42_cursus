/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:21:49 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:21:43 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strnstr_test(void)
{
	char *name = "FT_STRNSTR";
	char *(*pt)(const char *, const char *, size_t);
	int i;
	int j;
	const char haystack[5][20] = {"Enfaite ouai", "La rosterlinette", "", "ooooui", "La rosterlinette"};
	const char needle[5][20] = {"faite ouai", "",  "", "nom", "La rosterlinette"};
	size_t len[5] = {20, 2, 10, 7, 0};

	print_begin(name);
	pt = ft_strnstr;
	i = 0;
	j = 0;
	while (i <= 2)
	{
		if (strcmp(pt(haystack[i], needle[i], len[i]), strnstr(haystack[i], needle[i], len[i])) == 0)
			print_ok(i + 1);
		else
		{
			print_wrong_char(pt(haystack[i], needle[i], len[i]), strnstr(haystack[i], needle[i], len[i]), (i + 1));
			j++;
		}
		i++;
	}
	while (i > 2 && i <=4)
	{
		if (pt(haystack[i], needle[i], len[i]) == NULL && strnstr(haystack[i], needle[i], len[i]) == NULL)
			print_ok(i + 1);
		else
		{
			print_wrong_char(pt(haystack[i], needle[i], len[i]), strnstr(haystack[i], needle[i], len[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
