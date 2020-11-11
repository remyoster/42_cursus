/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:59:54 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:35:24 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strjoin_test(void)
{
	char *name = "FT_STRJOIN";
	char	*(*pt)(char const*, char const*);
	int i;
	int j;
	char const s1[4][20] = {"La rosterlinette", "La rosterlinette", "La rosterlinette ", ""};
	char const s2[4][20] = {" est top", "", "est magique ", "La rosterlinette"};
	char const exp[4][40] = {"La rosterlinette est top", "La rosterlinette", "La rosterlinette est magique ", "La rosterlinette"};

	print_begin(name);
	pt = ft_strjoin;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if ((strcmp(pt(s1[i], s2[i]), exp[i])) ==  0)
			print_ok(i + 1);
		else
		{
			print_wrong_char(pt(s1[i], s2[i]), exp[i], (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
