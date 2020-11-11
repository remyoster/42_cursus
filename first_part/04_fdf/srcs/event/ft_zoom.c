/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:12:28 by roster            #+#    #+#             */
/*   Updated: 2019/02/13 13:01:09 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../../includes/fdf.h"

static void	ft_zoom_more_iso(t_win *win)
{
	if (win->evt.gap_y + ZOOM < 101)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		mlx_destroy_image(win->mlx_ptr, win->img_ptr);
		win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT - HEIGHT / 7);
		win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
				&(win->s_l), &(win->endian));
		if (win->evt.gap_y == 1 && ZOOM > 1)
			win->evt.gap_y = ZOOM - 1;
		else
			win->evt.gap_y = win->evt.gap_y + ZOOM;
		win->evt.gap_x = win->evt.gap_y * 2;
		ft_first_pt(win);
		win->evt.dx_st = win->evt.dx_st + win->dir_h * CONST;
		win->evt.dy_st = win->evt.dy_st + win->dir_v * CONST;
		ft_fill_window_iso(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
				win->mark_x, win->mark_y);
		ft_legends(*win);
	}
}

static void	ft_zoom_more(t_win *win)
{
	if (win->evt.gap_y + ZOOM < 101)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		mlx_destroy_image(win->mlx_ptr, win->img_ptr);
		win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT - HEIGHT / 7);
		win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
				&(win->s_l), &(win->endian));
		if (win->evt.gap_y == 1 && ZOOM > 1)
			win->evt.gap_y = ZOOM - 1;
		else
			win->evt.gap_y = win->evt.gap_y + ZOOM;
		win->evt.gap_x = win->evt.gap_y * 2;
		ft_first_pt(win);
		win->evt.dx_st = win->evt.dx_st + win->dir_h * CONST;
		win->evt.dy_st = win->evt.dy_st + win->dir_v * CONST;
		ft_fill_window_para(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
				win->mark_x, win->mark_y);
		ft_legends(*win);
	}
}

static void	ft_zoom_less_iso(t_win *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT - HEIGHT / 7);
	win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
			&(win->s_l), &(win->endian));
	if (win->evt.gap_y <= ZOOM)
		win->evt.gap_y = 1;
	else
		win->evt.gap_y = win->evt.gap_y - ZOOM;
	win->evt.gap_x = win->evt.gap_y * 2;
	ft_first_pt(win);
	win->evt.dx_st = win->evt.dx_st + win->dir_h * CONST;
	win->evt.dy_st = win->evt.dy_st + win->dir_v * CONST;
	ft_fill_window_iso(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
			win->mark_x, win->mark_y);
	ft_legends(*win);
}

static void	ft_zoom_less(t_win *win)
{
	if (win->proj == 0)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		mlx_destroy_image(win->mlx_ptr, win->img_ptr);
		win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH,
				HEIGHT - HEIGHT / 7);
		win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
				&(win->s_l), &(win->endian));
		if (win->evt.gap_y <= ZOOM)
			win->evt.gap_y = 1;
		else
			win->evt.gap_y = win->evt.gap_y - ZOOM;
		win->evt.gap_x = win->evt.gap_y * 2;
		ft_first_pt(win);
		win->evt.dx_st = win->evt.dx_st + win->dir_h * CONST;
		win->evt.dy_st = win->evt.dy_st + win->dir_v * CONST;
		ft_fill_window_para(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
				win->mark_x, win->mark_y);
		ft_legends(*win);
	}
	else
		ft_zoom_less_iso(win);
}

void		ft_zoom(int key, t_win *win)
{
	if (key == 24 || key == 69)
	{
		if (win->proj == 0)
			ft_zoom_more(win);
		else
			ft_zoom_more_iso(win);
	}
	else
		ft_zoom_less(win);
}
