/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:56:56 by roster            #+#    #+#             */
/*   Updated: 2018/11/15 13:39:22 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strclr_test(void)
{
	char *name = "FT_STRCLR";
	int bol;
	char s[25] = "La\0\0roster\0linette";
	char d[25] = "\0\0\0\0\0\0\0\0\0\0";

	print_begin(name);
	ft_strclr(s);
	if (strcmp(s, d) == 0)
	{
		print_ok(1);
		bol = 0;
	}
	else
	{
		print_wrong_char(&s[2], &d[2], 1);
		bol = 1;
	}
	print_end(bol);
	return (0);
}
