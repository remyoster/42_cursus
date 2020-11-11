/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:53:18 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 15:10:09 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_atoi_test(void)
{
	char *name = "FT_ATOI";
	int (*pt)(char const *);
	int i;
	int j;
	char const s1[7][20] = {"--hghghudv45 ", "-2147483648", "2147483647", "", "T@^*&FHh9fhfd", "--04", "+457"};

	print_begin(name);
	pt = ft_atoi;
	i = 0;
	j = 0;
	while (i <= 6)
	{
		if (pt(s1[i]) == atoi(s1[i]))
			print_ok(i + 1);
		else
		{
			print_wrong_int(pt(s1[i]), atoi(s1[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
