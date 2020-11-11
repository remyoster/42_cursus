/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srch_extrem_val_fdf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:02:21 by roster            #+#    #+#             */
/*   Updated: 2019/02/13 07:06:16 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	ft_min_value(t_pix **tab, size_t i, size_t j)
{
	int		min;
	size_t	x;
	size_t	y;

	y = 0;
	min = tab[y][0].z;
	while (y < i)
	{
		x = 0;
		while (x < j)
		{
			if (tab[y][x].z < min)
				min = tab[y][x].z;
			x++;
		}
		y++;
	}
	return (min);
}

static int	ft_max_value(t_pix **tab, size_t i, size_t j)
{
	int		max;
	size_t	x;
	size_t	y;

	y = 0;
	max = tab[y][0].z;
	while (y < i)
	{
		x = 0;
		while (x < j)
		{
			if (tab[y][x].z > max)
				max = tab[y][x].z;
			x++;
		}
		y++;
	}
	return (max);
}

int			ft_srch_extrem_val_fdf(t_pix **tab, size_t i, size_t j, int mod)
{
	if (mod == 0)
		return (ft_min_value(tab, i, j));
	else
		return (ft_max_value(tab, i, j));
}
