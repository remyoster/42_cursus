/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:22:18 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:13:52 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strdup_test(void)
{
	char *name = "FT_STRDUP";
	char *(*pt)(char const *);
	int i;
	int j;
	char const s1[3][20] = {" ", "La rosterlinette", ""};

	print_begin(name);
	pt = ft_strdup;
	i = 0;
	j = 0;
	while (i <= 2)
	{
		if (strcmp(pt(s1[i]), strdup(s1[i])) == 0)
			print_ok(i + 1);
		else
		{
			print_wrong_char(pt(s1[i]), strdup(s1[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
