/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:15:26 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:32:05 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

void	f2(unsigned int i, char *s)
{
		if (i >= 4)
			*s = 'f';
}

int		ft_striteri_test(void)
{
	char *name = "FT_STRITERI";
	void	(*pt)(unsigned int, char *);
	int bol;
	char s[] = "La rosterlinette";
	char exp[] = "La rffffffffffff";

	print_begin(name);
	pt = f2;
	ft_striteri(s, pt);
	if (strcmp(s, exp) == 0)
	{
		print_ok(1);
		bol = 0;
	}
	else
	{
		print_wrong_char(s, exp, 1);
		bol = 1;
	}
	print_end(bol);
	return (bol);
}
