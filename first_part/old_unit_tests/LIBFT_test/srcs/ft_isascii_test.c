/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 11:39:34 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:24:51 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_isascii_test(void)
{
	char *name = "FT_ISASCII";
	int (*pt)(int);
	int i;
	int j;
	int c[6] = {'a', ' ', 'B', '\0', '\n', 127};

	print_begin(name);
	pt = ft_isascii;
	i = 0;
	j = 0;
	while (i <= 5)
	{
		if (pt(c[i]) == isascii(c[i]))
			print_ok(i + 1);
		else
		{
			print_wrong_int(pt(c[i]), isascii(c[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
