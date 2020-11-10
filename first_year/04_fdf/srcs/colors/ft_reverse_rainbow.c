/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rainbow_verse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:34:14 by lojesu            #+#    #+#             */
/*   Updated: 2019/02/11 19:18:07 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <stdlib.h>

/*
** in the order of function
** red
** orange
** yellow
** green
** blue
** purple
*/

static void	ft_bearing_hot(t_win *win, int max, int min, int i)
{
	if (i < (max - min) / 6)
	{
		win->rgb.r = 255;
		win->rgb.g = 0 + i * (153 / ((max - min) / 6));
		win->rgb.b = 0;
	}
	if (i >= ((max - min) / 6) && i < (2 * ((max - min) / 6)))
	{
		win->rgb.r = 255;
		win->rgb.g = 153 + (i - ((max - min) / 6)) * (102 / ((max - min) / 6));
		win->rgb.b = 0;
	}
	if (i >= (2 * ((max - min) / 6)) && i < (3 * ((max - min) / 6)))
	{
		win->rgb.r = 255 - (i - 2 * ((max - min) / 6)) *
			(255 / ((max - min) / 6));
		win->rgb.g = 255;
		win->rgb.b = 0;
	}
}

static void	ft_bearing_cold(t_win *win, int max, int min, int i)
{
	if (i >= (3 * ((max - min) / 6)) && i < (4 * ((max - min) / 6)))
	{
		win->rgb.r = 0;
		win->rgb.g = 255 - (i - 3 * ((max - min) / 6)) *
			(255 / ((max - min) / 6));
		win->rgb.b = 0 + (i - 3 * ((max - min) / 6)) *
			(255 / ((max - min) / 6));
	}
	if (i >= (4 * ((max - min) / 6)) && i < (5 * ((max - min) / 6)))
	{
		win->rgb.r = 0 + (i - 4 * ((max - min) / 6)) *
			(102 / ((max - min) / 6));
		win->rgb.g = 0;
		win->rgb.b = 255 - (i - 4 * ((max - min) / 6)) *
			(51 / ((max - min) / 6));
	}
	if (i >= (5 * ((max - min) / 6)))
	{
		win->rgb.r = 102;
		win->rgb.g = 0;
		win->rgb.b = 204;
	}
}

static void	ft_give_valor_to_color(t_win win, int *tab, int min)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < win.pos.y)
	{
		j = 0;
		while (j < win.pos.x)
		{
			win.pix[i][j].h = tab[win.pix[i][j].z - min];
			j++;
		}
		i++;
	}
}

static void	ft_special_reverse_rainbow(t_win *win, int max, int min, int *tab)
{
	int	i;

	i = 0;
	while (i <= max - min)
	{
		if (i == 0)
		{
			win->rgb.r = 255;
			win->rgb.g = 0;
			win->rgb.b = 0;
		}
		else if (i == max)
		{
			win->rgb.r = 102;
			win->rgb.g = 0;
			win->rgb.b = 204;
		}
		else
		{
			win->rgb.r = 0;
			win->rgb.g = 255;
			win->rgb.b = 0;
		}
		tab[i++] = ft_rgb_to_int(win->rgb.r, win->rgb.g, win->rgb.b);
	}
}

void		ft_reverse_rainbow(t_win win)
{
	int		i;
	int		max;
	int		min;
	int		*tab;

	i = 0;
	max = ft_srch_extrem_val_fdf(win.pix, win.pos.y, win.pos.x, 1);
	min = ft_srch_extrem_val_fdf(win.pix, win.pos.y, win.pos.x, 0);
	if (!(tab = (int*)malloc(sizeof(int) * (max - min) + 2)))
		return ;
	if ((max - min) < 6)
		ft_special_reverse_rainbow(&win, max, min, tab);
	else
	{
		while (i <= max - min)
		{
			ft_bearing_hot(&win, max, min, i);
			ft_bearing_cold(&win, max, min, i);
			tab[i] = ft_rgb_to_int(win.rgb.r, win.rgb.g, win.rgb.b);
			i++;
		}
	}
	ft_give_valor_to_color(win, tab, min);
	free(tab);
	tab = NULL;
}
