/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:33:30 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 16:18:23 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rosterlinette.h"

int		ft_strsplit_test(void)
{
	char const	*s;
	char c;
	char **tab;
	char tabcmp[3][10] = {"salut", "les", "etudiants"};
	int x;
	int i;
	int j;

	x = 0;
	printf(YELLOW"TEST DE FT_STRSPLIT : "RESET);

	TEST1
		s = "*salut*les***etudiants*";
	c = '*';
	tab = ft_strsplit(s, c);
	i = 0;
	j = 0;
	while (i < 3)
	{	
		if (strcmp(tab[i], tabcmp[i]) == 0)
			j++;
		i++;
	}
	if (j < 3)
	{
		WRONG
			printf("PERSONAL : %s--%s--%s\n", tab[0], tab[1], tab[2]);
		printf("OFFICIAL : %s--%s--%s\n", tabcmp[0], tabcmp[1], tabcmp[2]);
	}
	if (j == 3)
	{
		x++;
		OK
	}
	TEST2
		s = "salut*les***etudiants";
	c = '*';
	tab = ft_strsplit(s, c);
	i = 0;
	j = 0;
	while (i < 3)
	{	
		if (strcmp(tab[i], tabcmp[i]) == 0)
			j++;
		i++;
	}
	if (j < 3)
	{
		WRONG
			printf("PERSONAL : %s--%s--%s\n", tab[0], tab[1], tab[2]);
		printf("OFFICIAL : %s--%s--%s\n", tabcmp[0], tabcmp[1], tabcmp[2]);
	}
	if (j == 3)
	{
		x++;
		OK
	}
	TEST3
		s = "****salut*les***etudiants";
	c = '*';
	tab = ft_strsplit(s, c);
	i = 0;
	j = 0;
	while (i < 3)
	{	
		if (strcmp(tab[i], tabcmp[i]) == 0)
			j++;
		i++;
	}
	if (j < 3)
	{
		WRONG
			printf("PERSONAL : %s--%s--%s\n", tab[0], tab[1], tab[2]);
		printf("OFFICIAL : %s--%s--%s\n", tabcmp[0], tabcmp[1], tabcmp[2]);

	}
	if (j == 3)
	{
		x++;
		OK
	}
	TEST4
		s = "salut*les***etudiants*****";
	c = '*';
	tab = ft_strsplit(s, c);
	i = 0;
	j = 0;
	while (i < 3)
	{	
		if (strcmp(tab[i], tabcmp[i]) == 0)
			j++;
		i++;
	}
	if (j < 3)
	{
		WRONG
			printf("PERSONAL : %s--%s--%s\n", tab[0], tab[1], tab[2]);
		printf("OFFICIAL : %s--%s--%s\n", tabcmp[0], tabcmp[1], tabcmp[2]);

	}
	if (j == 3)
	{
		x++;
		OK
	}
	printf("\n----------------------------------------------------------\n");
	if (x == 4)
		return (0);
	return (1);
}
