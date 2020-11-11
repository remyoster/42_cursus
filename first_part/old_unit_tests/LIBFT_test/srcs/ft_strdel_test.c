/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:14:45 by roster            #+#    #+#             */
/*   Updated: 2018/11/15 12:54:21 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strdel_test(void)
{
	char *name = "FT_STRDEL";
	int bol;
	char **as;

	if (!(as = (char**)malloc(sizeof(char*) * 10)))
		return (0);
	print_begin(name);
	ft_strdel(as);
	if (*as == NULL)
	{
		print_ok(1);
		bol = 0;
	}
	else
	{
		printf("Test1: "RED"WRONG\nFAILED TO FREE\n"RESET);
		printf("|%p|", as);
		printf("|%p|", NULL);
		bol = 1;
	}
	print_end(bol);
	return (0);
}
