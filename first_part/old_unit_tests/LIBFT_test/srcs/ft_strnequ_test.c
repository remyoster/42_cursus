/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:42:17 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:34:14 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strnequ_test(void)
{
	char *name = "FT_STRNEQU";
	int	(*pt)(char const *, char const *, size_t);
	int i;
	int j;
	char const s1[4][20] = {" ", "La rosterlinette", "La rosterlinette", ""};
	char const s2[4][20] = {" ", "est magique ", "La rosterlinette", ""};
	size_t n[] = {5, 4, 10, 3};
	int	exp[] = {1, 0, 1, 1};

	print_begin(name);
	pt = ft_strnequ;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (pt(s1[i], s2[i], n[i]) == exp[i])
			print_ok(i + 1);
		else
		{
			print_wrong_int(pt(s1[i], s2[i], n[i]), exp[i], (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
