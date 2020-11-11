/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:22:54 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:02:46 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_bzero_test(void)
{
	char *name = "FT_BZERO";
	void (*pt)(void *, size_t);
	char s1[4][20] = {"aaaaaaaaaaaaaa", "est magique", "La rosterlinette", ""};
	char s2[4][20] = {"aaaaaaaaaaaaaa", "est magique", "La rosterlinette", ""};
	size_t len[4] = {18, 0, 5, 2};
	int i;
	int j;

	print_begin(name);
	pt = ft_bzero;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		pt(s1[i], len[i]);
		bzero(s2[i], len[i]);
		if (strcmp(s1[i], s2[i]) == 0)
			print_ok(i + 1);
		if (strcmp(s1[i], s2[i]) != 0)
		{
			print_wrong_char(s1[i], s2[i], (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
