/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 11:30:11 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:23:41 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_isdigit_test(void)
{
	char *name = "FT_ISDIGIT";
	int (*pt)(int);
	int i;
	int j;
	int c[3] = {'0', ' ', '5'};

	print_begin(name);
	pt = ft_isdigit;
	i = 0;
	j = 0;
	while (i <= 2)
	{
		if (pt(c[i]) == isdigit(c[i]))
			print_ok(i + 1);
		else
		{
			print_wrong_int(pt(c[i]), isdigit(c[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
