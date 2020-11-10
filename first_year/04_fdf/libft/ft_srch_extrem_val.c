/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srch_extrem_val.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:00:01 by roster            #+#    #+#             */
/*   Updated: 2019/02/06 17:46:43 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	ft_min_value(int **tab, size_t i, size_t j)
{
	int		min;
	size_t	x;
	size_t	y;

	y = 0;
	while (y < i)
	{
		x = 0;
		while (x < j)
		{
			if (tab[y][x] < min)
				min = tab[y][x];
			x++;
		}
		y++;
	}
	return (min);
}

static int	ft_max_value(int **tab, size_t i, size_t j)
{
	int		max;
	size_t	x;
	size_t	y;

	y = 0;
	while (y < i)
	{
		x = 0;
		while (x < j)
		{
			if (tab[y][x] > max)
				max = tab[y][x];
			x++;
		}
		y++;
	}
	return (max);
}

int			ft_srch_extrem_val(int **tab, size_t i, size_t j, int mod)
{
	if (mod == 0)
		return (ft_min_value(tab, i, j));
	else
		return (ft_max_value(tab, i, j));
}
