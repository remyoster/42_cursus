/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mountain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:03:58 by roster            #+#    #+#             */
/*   Updated: 2019/02/11 19:17:25 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_give_valor_to_color(t_win win, int *tab)
{
	size_t x;
	size_t y;

	y = 0;
	while (y < win.pos.y)
	{
		x = 0;
		while (x < win.pos.x)
		{
			if (win.pix[y][x].z < -20)
				win.pix[y][x].h = 75;
			else if (win.pix[y][x].z >= -20 && win.pix[y][x].z <= 100)
				win.pix[y][x].h = tab[win.pix[y][x].z + 20];
			else if (win.pix[y][x].z >= 101 && win.pix[y][x].z <= 500)
				win.pix[y][x].h = 3348992;
			else
				win.pix[y][x].h = 16777215;
			x++;
		}
		y++;
	}
}

static void	ft_bearing(size_t i, t_win *win)
{
	if (i <= 20)
	{
		win->rgb.r = 0;
		win->rgb.g = 0;
		win->rgb.b = 75 + (i * 9);
	}
	if (i > 20 && i <= 80)
	{
		win->rgb.r = 0;
		win->rgb.g = 255 - (i - 20) * 4;
		win->rgb.b = 0;
	}
	if (i > 80 && i < 420)
	{
		win->rgb.r = 179 - ((i - 80) / 3);
		win->rgb.g = 89 - ((i - 80) / 5);
		win->rgb.b = 0;
	}
}

void		ft_mountain(t_win win)
{
	size_t	i;
	int		tab[420];

	i = 0;
	while (i < 420)
	{
		ft_bearing(i, &win);
		tab[i] = ft_rgb_to_int(win.rgb.r, win.rgb.g, win.rgb.b);
		i++;
	}
	ft_give_valor_to_color(win, tab);
}
