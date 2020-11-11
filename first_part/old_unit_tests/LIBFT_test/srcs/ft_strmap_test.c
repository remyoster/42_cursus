/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:03:35 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:32:24 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

char	f3(char c)
{
	if (c == 'l')
		c = '\0';
	return (c);
}

int		ft_strmap_test(void)
{
	char *name = "FT_STRMAP";
	char	(*pt)(char);
	int bol;
	char const s[17] = "La rosterlinette";
	char exp[] = "La roster";

	print_begin(name);
	pt = f3;
	if (strcmp(ft_strmap(s, pt), exp) == 0)
	{
		print_ok(1);
		bol = 0;
	}
	else
	{
		print_wrong_char(ft_strmap(s, pt), exp, 1);
		bol = 1;
	}
	print_end(bol);
	return (bol);
}
