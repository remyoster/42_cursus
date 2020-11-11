/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 08:40:20 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:29:06 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_memalloc_test(void)
{
	char *name = "FT_MEMALLOC";
	void *(*pt)(size_t);
	int i;
	int j;
	size_t size[4] = {10000000, 1000000, 1000, 65538};

	print_begin(name);
	pt = ft_memalloc;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (pt(size[i]) != NULL && size[i] > 0 && size[i] < SIZE_MAX)
			print_ok(i + 1);
		if (pt(size[i]) != NULL && size[i] > SIZE_MAX) 
		{
			print_wrong_memory(pt(size[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
