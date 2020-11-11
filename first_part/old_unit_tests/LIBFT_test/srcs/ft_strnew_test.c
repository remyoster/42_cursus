/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:55:02 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:30:14 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strnew_test(void)
{
	char *name = "FT_STRNEW";
	char *(*pt)(size_t);
	int i;
	int j;
	size_t size[4] = {10, 0, 5, 8};
	char	s1[4][20] = {"", "", "", ""};

	print_begin(name);
	pt = ft_strnew;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (memcmp(pt(size[i]), s1[i], size[i]) == 0)
			print_ok(i + 1);
		else
		{
			print_wrong_char(pt(size[i]), s1[i], (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
