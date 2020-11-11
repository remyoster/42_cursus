/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 11:46:18 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:25:20 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_isprint_test(void)
{
	char *name = "FT_ISPRINT";
	int (*pt)(int);
	int i;
	int j;
	int c[4] = {'~', ' ', 'B', '+'};

	print_begin(name);
	pt = ft_isprint;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (pt(c[i]) == isprint(c[i]))
			print_ok(i + 1);
		else
		{
			print_wrong_int(pt(c[i]), isprint(c[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
