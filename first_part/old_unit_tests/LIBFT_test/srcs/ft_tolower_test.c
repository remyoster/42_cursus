/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 11:54:53 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:26:31 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_tolower_test(void)
{
	char *name = "FT_TOLOWER";
	int (*pt)(int);
	int i;
	int j;
	int c[3] = {'a', ' ', 'B'};

	print_begin(name);
	pt = ft_tolower;
	i = 0;
	j = 0;
	while (i <= 2)
	{
		if (pt(c[i]) == tolower(c[i]))
			print_ok(i + 1);
		else
		{
			print_wrong_int(pt(c[i]), tolower(c[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
