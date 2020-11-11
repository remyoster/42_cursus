/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_high.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:03:00 by roster            #+#    #+#             */
/*   Updated: 2019/02/12 13:46:14 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../../includes/fdf.h"

static void	ft_high_more_iso(t_win *win)
{
	if (win->cst_proj < 90)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		mlx_destroy_image(win->mlx_ptr, win->img_ptr);
		win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH,
				HEIGHT - HEIGHT / 7);
		win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
				&(win->s_l), &(win->endian));
		win->cst_proj = win->cst_proj + 0.1;
		ft_fill_window_iso(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
				win->mark_x, win->mark_y);
		ft_legends(*win);
	}
}

static void	ft_high_more(t_win *win)
{
	if (win->proj == 0)
	{
		if (win->cst_proj < 90)
		{
			mlx_clear_window(win->mlx_ptr, win->win_ptr);
			mlx_destroy_image(win->mlx_ptr, win->img_ptr);
			win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH,
					HEIGHT - HEIGHT / 7);
			win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
					&(win->s_l), &(win->endian));
			win->cst_proj = win->cst_proj + 0.1;
			ft_fill_window_para(win);
			mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
					win->mark_x, win->mark_y);
			ft_legends(*win);
		}
	}
	else
		ft_high_more_iso(win);
}

static void	ft_high_less_iso(t_win *win)
{
	if (win->cst_proj > 0.1)
	{
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		mlx_destroy_image(win->mlx_ptr, win->img_ptr);
		win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH,
				HEIGHT - HEIGHT / 7);
		win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
				&(win->s_l), &(win->endian));
		win->cst_proj = win->cst_proj - 0.1;
		ft_fill_window_iso(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
				win->mark_x, win->mark_y);
		ft_legends(*win);
	}
}

static void	ft_high_less(t_win *win)
{
	if (win->proj == 0)
	{
		if (win->cst_proj > 0.1)
		{
			mlx_clear_window(win->mlx_ptr, win->win_ptr);
			mlx_destroy_image(win->mlx_ptr, win->img_ptr);
			win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH,
					HEIGHT - HEIGHT / 7);
			win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
					&(win->s_l), &(win->endian));
			win->cst_proj = win->cst_proj - 0.1;
			ft_fill_window_para(win);
			mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
					win->mark_x, win->mark_y);
			ft_legends(*win);
		}
	}
	else
		ft_high_less_iso(win);
}

void		ft_high(int key, t_win *win)
{
	if (key == 43)
		ft_high_less(win);
	else
		ft_high_more(win);
}
