/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:02:59 by roster            #+#    #+#             */
/*   Updated: 2018/11/15 11:51:17 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_memdel_test(void)
{
	char *name = "FT_MEMDEL";
	int bol;
	void **ap;

	if (!(ap = (void**)malloc(sizeof(size_t*) * 10)))
		return (0);
	print_begin(name);
	ft_memdel(ap);
	if (*ap == NULL)
	{
		print_ok(1);
		bol = 0;
	}
	else 
	{
		printf("Test1: "RED"WRONG\nFAILED TO FREE\n"RESET);
		printf("|%p|", ap);
		printf("|%p|", NULL);
		bol = 1;
	}
	print_end(bol);
	return (0);
}
