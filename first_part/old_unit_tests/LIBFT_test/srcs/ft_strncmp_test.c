/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:40:15 by roster            #+#    #+#             */
/*   Updated: 2018/11/19 11:14:41 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int 	test(int (*pt)(char const *, char const *, size_t), char const s1[4][20], char const s2[4][20], size_t n[])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (pt(s1[i], s2[i], n[i]) == strncmp(s1[i], s2[i], n[i]))
			print_ok(i + 1);

		if (pt(s1[i], s2[i], n[i]) != strncmp(s1[i], s2[i], n[i]))
		{
			print_wrong_int(pt(s1[i], s2[i], n[i]), strncmp(s1[i],s2[i], n[i]), (i + 1));
			j++;
		}
		i++;
	}
	return (j);
}

int		ft_strncmp_test(void)
{
	char *name = "FT_STRNCMP";
	int (*pt)(char const *, char const *, size_t);
	int bol;
	char const s1[4][20] = {" ", "La rosterlinette", "La rosterlinette", ""};
	char const s2[4][20] = {" ", "est magique ", "La risterlinette", ""};
	size_t n[] = {1, 3, 4, 0};

	print_begin(name);
	pt = ft_strncmp;
	bol = test(pt, s1, s2, n);
	print_end(bol);
	return (bol);
}
