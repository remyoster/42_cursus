/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:16:36 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 16:14:25 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strtrim_test(void)
{
	char *name = "FT_STRTRIM";
	char *(*pt)(char const *);
	int i;
	int j;
	char const s1[4][20] = {" roster   ", "roster", " roster", "roster  "};
	char const s2[20] = "roster";

	print_begin(name);
	pt = ft_strtrim;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (strcmp(pt(s1[i]), s2) == 0)
			print_ok(i + 1);
		else
		{
			print_wrong_char(pt(s1[i]), s2, (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
