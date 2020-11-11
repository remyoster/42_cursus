/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:13:49 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 15:10:57 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strlen_test(void)
{
	char *name = "FT_STRLEN";
	size_t (*pt)(char const *);
	int i;
	int j;
	char const s1[4][20] = {" ", "La rosterlinette", "La rosterlinette", ""};

	print_begin(name);
	pt = ft_strlen;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (pt(s1[i]) == strlen(s1[i]))
			print_ok(i + 1);
		else
		{
			print_wrong_int(pt(s1[i]), strlen(s1[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
