/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 08:58:18 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:33:32 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strequ_test(void)
{
	char *name = "FT_STREQU";
	int	(*pt)(char const *, char const *);
	int i;
	int j;
	char const s1[4][20] = {" ", "La rosterlinette", "La rosterlinette", ""};
	char const s2[4][20] = {" ", "est magique ", "La rosterlinette", ""};
	int	exp[] = {1, 0, 1, 1};

	print_begin(name);
	pt = ft_strequ;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (pt(s1[i], s2[i]) == exp[i])
			print_ok(i + 1);
		else
		{
			print_wrong_int(pt(s1[i], s2[i]), exp[i], (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
