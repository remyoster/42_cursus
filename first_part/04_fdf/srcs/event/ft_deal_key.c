/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:26:28 by roster            #+#    #+#             */
/*   Updated: 2019/02/12 13:43:36 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../../includes/fdf.h"
#include <stdlib.h>

static void	ft_base_menu(int key, t_win *win)
{
	if (key == 18 || key == 83)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		win->proj = 0;
		ft_fill_window_para(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
				win->mark_x, win->mark_y);
		ft_legends(*win);
	}
	else if (key == 19 || key == 84)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		win->proj = 1;
		ft_first_pt(win);
		ft_fill_window_iso(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
				win->mark_x, win->mark_y);
		ft_legends(*win);
	}
	else if (key == 53)
		exit(1);
}

int			ft_deal_key(int key, t_win *win)
{
	if (win->proj != -1)
	{
		if ((key >= 123 && key <= 126) || (key >= 0 && key <= 2) || key == 13)
			ft_arrow(key, win);
		if (key == 43 || key == 47)
			ft_high(key, win);
		if (key == 24 || key == 69 || key == 27 || key == 78)
			ft_zoom(key, win);
		if (key == 48)
			ft_recenter(win);
		if (key == 30 || key == 33 || key == 49)
			ft_coloring(key, win);
		if (key == 35)
			ft_change_proj(win);
		if (key == 53)
			exit(1);
	}
	else
		ft_base_menu(key, win);
	return (0);
}
