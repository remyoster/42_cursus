/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_arrow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:50:09 by roster            #+#    #+#             */
/*   Updated: 2019/02/12 13:44:15 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../../includes/fdf.h"

static void	ft_right_arrow(t_win *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT - HEIGHT / 7);
	win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
			&(win->s_l), &(win->endian));
	win->evt.dx_st = win->evt.dx_st - CONST;
	win->dir_h--;
	if (win->proj == 0)
		ft_fill_window_para(win);
	else
	{
		win->dir_v++;
		win->evt.dy_st = win->evt.dy_st + CONST;
		ft_fill_window_iso(win);
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
			win->mark_x, win->mark_y);
	ft_legends(*win);
}

static void	ft_left_arrow(t_win *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT - HEIGHT / 7);
	win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
			&(win->s_l), &(win->endian));
	win->evt.dx_st = win->evt.dx_st + CONST;
	win->dir_h++;
	if (win->proj == 0)
		ft_fill_window_para(win);
	else
	{
		win->dir_v--;
		win->evt.dy_st = win->evt.dy_st - CONST;
		ft_fill_window_iso(win);
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
			win->mark_x, win->mark_y);
	ft_legends(*win);
}

static void	ft_up_arrow(t_win *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT - HEIGHT / 7);
	win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
			&(win->s_l), &(win->endian));
	win->evt.dy_st = win->evt.dy_st + CONST;
	win->dir_v++;
	if (win->proj == 0)
		ft_fill_window_para(win);
	else
	{
		win->dir_h++;
		win->evt.dx_st = win->evt.dx_st + CONST;
		ft_fill_window_iso(win);
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
			win->mark_x, win->mark_y);
	ft_legends(*win);
}

static void	ft_down_arrow(t_win *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT - HEIGHT / 7);
	win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
			&(win->s_l), &(win->endian));
	win->evt.dy_st = win->evt.dy_st - CONST;
	win->dir_v--;
	if (win->proj == 0)
		ft_fill_window_para(win);
	else
	{
		win->dir_h--;
		win->evt.dx_st = win->evt.dx_st - CONST;
		ft_fill_window_iso(win);
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
			win->mark_x, win->mark_y);
	ft_legends(*win);
}

void		ft_arrow(int key, t_win *win)
{
	if (key == 124 || key == 2)
		ft_right_arrow(win);
	else if (key == 123 || key == 0)
		ft_left_arrow(win);
	else if (key == 126 || key == 13)
		ft_up_arrow(win);
	else
		ft_down_arrow(win);
}
