/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:44:26 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:32:40 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

char	f4(unsigned int i, char c)
{
	if (i > 8) 
		c = '\0';
	return (c);
}

int		ft_strmapi_test(void)
{
	char *name = "FT_STRMAPI";
	char	(*pt)(unsigned int, char);
	int bol;
	char const s[17] = "La rosterlinette";
	char exp[] = "La roster";

	print_begin(name);
	pt = f4;
	if (strcmp(ft_strmapi(s, pt), exp) == 0)
	{
		print_ok(1);
		bol = 0;
	}
	else
	{
		print_wrong_char(ft_strmapi(s, pt), exp, 1);
		bol = 1;
	}
	print_end(bol);
	return (bol);
}
