/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:36:17 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:08:28 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_memccpy_test(void)
{
	char *name = "FT_MEMCCPY";
	void *(*pt)(void *, const void *, int, size_t);
	int i;
	int j;
	char s1[5][20] = {"aaaaabaaaaaaaa", "est magique", "La rosterlinette", "", ""};
	const char s2[5][20] = {"lollolblol", "La panini", "La rosterlinette", "LOL", ""};
	int c[5] = {'b', 'p', 'o', 'd', 'e'};
	size_t len[5] = {15, 5, 20, 10, 8};

	print_begin(name);
	pt = ft_memccpy;
	i = 0;
	j = 0;
	while (i <= 2)
	{
		if (strcmp(pt(s1[i], s2[i], c[i], len[i]), memccpy(s1[i], s2[i], c[i], len[i])) == 0)
			print_ok(i + 1);
		else
		{
			print_wrong_char(pt(s1[i], s2[i], c[i], len[i]), memccpy(s1[i], s2[i], c[i], len[i]), (i + 1));
			j++;
		}
		i++;
	}
	while (i > 2 && i <= 4)
	{
		if (pt(s1[i], s2[i], c[i], len[i]) == NULL && memccpy(s1[i], s2[i], c[i], len[i]) == NULL)
			print_ok(i + 1);
		else
		{
			print_wrong_char(pt(s1[i], s2[i], c[i], len[i]), memccpy(s1[i], s2[i], c[i], len[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
