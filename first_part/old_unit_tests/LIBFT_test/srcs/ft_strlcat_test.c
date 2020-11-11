/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:03:51 by roster            #+#    #+#             */
/*   Updated: 2018/11/21 14:42:54 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strlcat_test(void)
{
	char *name = "FT_STRLCAT";
	size_t (*pt)(char *, const char *, size_t);
	int i;
	int j;
	char  dst[4][16] = {"aaaaaa", "bbb", "ccccc", ""};
	char const src[4][16] = {"aaa", "bbbbbb", "ccccc", ""};
	size_t size[4] = {5, 3, 5, 5};

	print_begin(name);
	pt = ft_strlcat;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (pt(dst[i], src[i], size[i]) == strlcat(dst[i], src[i], size[i]))
			print_ok(i + 1);
		else
		{
			print_wrong_size_t(pt(dst[i], src[i], size[i]), strlcat(dst[i], src[i], size[i]), (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
