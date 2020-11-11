/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 11:35:52 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:24:17 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_isalnum_test(void)
{
	char *name = "FT_ISALNUM";
	int (*pt)(int);
	int i;
	int j;
	int c[5] = {'a', ' ', 'B', '8', '0'};

	print_begin(name);
	pt = ft_isalnum;
	i = 0;
	j = 0;
	while (i <= 4)
	{
		if (pt(c[i]) == isalnum(c[i]))
			print_ok(i + 1);
		else
		{
			print_wrong_int(pt(c[i]), isalnum(c[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
