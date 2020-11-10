/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:55:47 by roster            #+#    #+#             */
/*   Updated: 2018/11/21 08:08:28 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			if ((s[i + 1] == c && s[i] != c) || (s[i + 1] == '\0'))
				count++;
			i++;
		}
	}
	return (count);
}

static	char	**ft_fill_tab(char **tab, char c, char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[k] != '\0' && i < ft_count_word(s, c))
	{
		j = 0;
		while (s[k] == c)
			k++;
		while (s[k] != '\0' && s[k] != c)
		{
			tab[i][j] = s[k];
			k++;
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}

static char		**ft_malloc_tab(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**tab;

	i = 0;
	k = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_count_word(s, c) + 1))))
		return (0);
	while (i < ft_count_word(s, c))
	{
		j = 0;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k] != '\0')
		{
			j++;
			k++;
		}
		if (!(tab[i] = (char*)malloc(sizeof(char) * j + 1)))
			return (0);
		i++;
	}
	return (ft_fill_tab(tab, c, s));
}

char			**ft_strsplit(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_malloc_tab(s, c));
}
