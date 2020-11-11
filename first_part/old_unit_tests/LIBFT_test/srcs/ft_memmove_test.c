/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:12:11 by roster            #+#    #+#             */
/*   Updated: 2018/11/20 15:45:49 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_memmove_test(void)
{
	char *name = "FT_MEMMOVE";
	void *(*pt)(void *, const void *, size_t);
	int i;
	int j;
	char s1[5][20] = {"aaaaaaaaaaaaaa", "est magique", "La rosterlinette", "", ""};
	const char s2[5][20] = {"", "La panini", "La rosterlinette", "LOL", ""};
	size_t len[5] = {10, 8, 0, 2, 5};

	print_begin(name);
	pt = ft_memmove;
	i = 0;
	j = 0;
	while (i <= 4)
	{
		if (strcmp(pt(s1[i], s2[i], len[i]), memcpy(s1[i], s2[i], len[i])) == 0)
			print_ok(i + 1);

		if (strcmp(pt(s1[i], s2[i], len[i]), memcpy(s1[i], s2[i], len[i])) != 0)
		{
			print_wrong_char(pt(s1[i], s2[i], len[i]), memcpy(s1[i], s2[i], len[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
