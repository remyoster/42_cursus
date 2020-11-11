/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 08:54:25 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 16:01:53 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_itoa_test(void)
{
	char *name = "FT_ITOA";
	char *(*pt)(int);
	int i;
	int j;
	char const s1[5][20] = {"-2147483648", "2147483647", "0", "0", "77"};
	int	tab[5] = {-2147483648, 2147483647, 0, -0, 77};

	print_begin(name);
	pt = ft_itoa;
	i = 0;
	j = 0;
	while (i <= 4)
	{
		if (strcmp(pt(tab[i]), s1[i]) == 0)
			print_ok(i + 1);
		else
		{
			print_wrong_char(pt(tab[i]), s1[i], (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
