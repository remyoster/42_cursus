/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:17:31 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:22:23 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strcmp_test(void)
{
	char *name = "FT_STRCMP";
	int (*pt)(char const *, char const *);
	int i;
	int j;
	char const s1[4][20] = {" ", "La rosterlinette", "La rosterlinette", ""};
	char const s2[4][20] = {" ", "est magique ", "La rosterlinette", ""};

	print_begin(name);
	pt = ft_strcmp;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (pt(s1[i], s2[i]) == strcmp(s1[i], s2[i]))
			print_ok(i + 1);
		else
		{
			print_wrong_int(pt(s1[i], s2[i]), strcmp(s1[i],s2[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
