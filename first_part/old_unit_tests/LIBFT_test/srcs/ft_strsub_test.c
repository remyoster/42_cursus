/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 08:11:10 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 14:34:48 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strsub_test(void)
{
	char *name = "FT_STRSUB";
	char *(*pt)(char const *, unsigned int, size_t);
	int i;
	int j;
	unsigned int tab_start[] = {0, 21, 0};
	size_t tab_len[] = {16, 12, 0};	
	char const s1[] = "La rosterlinette est vraiment topissime";
	char const exp[3][20] = {"La rosterlinette", "vraiment top", ""};

	print_begin(name);
	pt = ft_strsub;
	i = 0;
	j = 0;
	while (i <= 2)
	{
		if (strcmp(pt(s1, tab_start[i], tab_len[i]), exp[i]) == 0)
			print_ok(i + 1);
		else
		{
			print_wrong_char(pt(s1, tab_start[i], tab_len[i]), exp[i], (i + 1));
			j++;
		}
		i++;
	}
	print_end(j);
	return (j);
}
