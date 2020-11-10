/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coloring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:27:28 by roster            #+#    #+#             */
/*   Updated: 2019/02/12 13:44:44 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../../includes/fdf.h"

static void	ft_brace_right(t_win *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT - HEIGHT / 7);
	win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
			&(win->s_l), &(win->endian));
	win->rgb.bol++;
	if (win->rgb.bol == 11)
		win->rgb.bol = 0;
	ft_colors(&(win->rgb));
	if (win->proj == 0)
		ft_fill_window_para(win);
	else
		ft_fill_window_iso(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
			win->mark_x, win->mark_y);
	ft_legends(*win);
}

static void	ft_brace_left(t_win *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT - HEIGHT / 7);
	win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
			&(win->s_l), &(win->endian));
	win->rgb.bol--;
	if (win->rgb.bol == -1)
		win->rgb.bol = 10;
	ft_colors(&(win->rgb));
	if (win->proj == 0)
		ft_fill_window_para(win);
	else
		ft_fill_window_iso(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
			win->mark_x, win->mark_y);
	ft_legends(*win);
}

static void	ft_reset_colors(t_win *win)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < win->pos.y)
	{
		j = 0;
		while (j < win->pos.x)
		{
			win->pix[i][j].h = win->pix[i][j].tmp;
			j++;
		}
		i++;
	}
	win->degrade = 0;
}

static void	ft_apply_degrade(t_win *win)
{
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_image(win->mlx_ptr, win->img_ptr);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT - HEIGHT / 7);
	win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
			&(win->s_l), &(win->endian));
	win->degrade++;
	if (win->degrade == 4)
		ft_reset_colors(win);
	ft_degrade(*win, win->degrade);
	if (win->proj == 1)
		ft_fill_window_iso(win);
	else
		ft_fill_window_para(win);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
			win->mark_x, win->mark_y);
	ft_legends(*win);
}

void		ft_coloring(int key, t_win *win)
{
	if (key == 30)
		ft_brace_right(win);
	else if (key == 33)
		ft_brace_left(win);
	else
		ft_apply_degrade(win);
}
