/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:45:05 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 16:15:03 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

void	f(char *s)
{
		*s = 'f';
}

int		ft_striter_test(void)
{
	char *name = "FT_STRITER";
	void	(*pt)(char *);
	int bol;
	char s[] = "La rosterlinette";
	char exp[] = "ffffffffffffffff";

	print_begin(name);
	pt = f;
	ft_striter(s, pt);
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
