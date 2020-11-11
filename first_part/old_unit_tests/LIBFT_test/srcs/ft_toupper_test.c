/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 11:51:01 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:27:56 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_toupper_test(void)
{
	char *name = "FT_TOUPPER";
	int (*pt)(int);
	int i;
	int j;
	int c[3] = {'a', ' ', 'B'};

	print_begin(name);
	pt = ft_toupper;
	i = 0;
	j = 0;
	while (i <= 2)
	{
		if (pt(c[i]) == toupper(c[i]))
			print_ok(i + 1);
		else
		{
			print_wrong_int(pt(c[i]), toupper(c[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
