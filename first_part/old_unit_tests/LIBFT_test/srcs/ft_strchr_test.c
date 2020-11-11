/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:52:49 by roster            #+#    #+#             */
/*   Updated: 2018/11/19 12:50:19 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strchr_test(void)
{
	char *name = "FT_STRCHR";
	char *(*pt)(const char *, int);
	int i;
	int j;
	char const s1[5][16] = {"La rosterlinette", "est magique", "mon pote", ":)", "La rosterlinette"};
	int	tab[5] = {76, 109, 101, 0, 77};

	print_begin(name);
	pt = ft_strchr;
	i = 0;
	j = 0;
	while (i <= 3)
	{
		if (strcmp(pt(s1[i], tab[i]), strchr(s1[i], tab[i])) == 0)
			print_ok(i + 1);
		else 
		{
			print_wrong_char(pt(s1[i], tab[i]), strchr(s1[i], tab[i]), (i + 1));
			j++;
		}
		i++;
	}
	if (pt(s1[i], tab[i]) == NULL && strchr(s1[i], tab[i]) == NULL)
		print_ok(i + 1);
	else 
	{
		print_wrong_char(pt(s1[i], tab[i]), strchr(s1[i], tab[i]), (i + 1));
		j++;
	}
	print_end(j);
	return (j);
}
