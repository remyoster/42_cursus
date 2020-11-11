/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 10:17:56 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:10:09 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_memcmp_test(void)
{
	char *name = "FT_MEMCMP";
	int (*pt)(const void *, const void *, size_t);
	int i;
	int j;
	char const s1[4][20] = {" ", "La rosterlinette", "La rosterlinette", ""};
	char const s2[4][20] = {" ", "est magique ", "La rosterlinette", ""};
	size_t n[4] = {1, 20, 2, 0};

	print_begin(name);
	pt = ft_memcmp;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (pt(s1[i], s2[i], n[i]) == memcmp(s1[i], s2[i], n[i]))
			print_ok(i + 1);

		if (pt(s1[i], s2[i], n[i]) != memcmp(s1[i], s2[i], n[i]))
		{
			print_wrong_int(pt(s1[i], s2[i], n[i]), memcmp(s1[i],s2[i], n[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
