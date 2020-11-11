/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_proj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:51:11 by roster            #+#    #+#             */
/*   Updated: 2019/02/12 13:44:33 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../../includes/fdf.h"

void	ft_change_proj(t_win *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT - HEIGHT / 7);
	win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
			&(win->s_l), &(win->endian));
	if (win->proj == 0)
	{
		win->proj++;
		ft_first_pt(win);
		ft_fill_window_iso(win);
	}
	else
	{
		win->proj--;
		ft_first_pt(win);
		ft_fill_window_para(win);
	}
	win->dir_h = 0;
	win->dir_v = 0;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
			win->mark_x, win->mark_y);
	ft_legends(*win);
}
