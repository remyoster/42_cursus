/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:45:58 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:01:11 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_memset_test(void)
{
	char *name = "FT_MEMSET";
	void *(*pt)(void *, int, size_t);
	char s1[4][20] = {"aaaaaaaaaaaaaaaa", "est magique", "La rosterlinette", ""};
	int tab[4] = {'b', 'L', '\0', 'a'};
	size_t len[4] = {6, 0, 5, 2};
	int i;
	int j;

	print_begin(name);
	pt = ft_memset;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (strcmp(pt(s1[i], tab[i], len[i]), memset(s1[i], tab[i], len[i])) == 0)
			print_ok(i + 1);

		if (strcmp(pt(s1[i], tab[i], len[i]), memset(s1[i], tab[i], len[i])) != 0)
		{
			print_wrong_char(pt(s1[i], tab[i], len[i]), memset(s1[i], tab[i], len[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
