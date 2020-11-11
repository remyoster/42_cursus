/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:57:57 by roster            #+#    #+#             */
/*   Updated: 2019/02/12 14:17:52 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "../../includes/fdf.h"
#include <unistd.h>
#include <stdlib.h>

static void	ft_first_pt2(t_win *win)
{
	if (win->pos.x < win->pos.y)
	{
		win->evt.dx_st = (WIDTH / 2) + (((win->pos.x)
					* win->evt.gap_y) / 2);
		win->evt.dy_st = ((HEIGHT - (HEIGHT / 7)) / 2) - (((win->pos.y)
					* ((win->evt.gap_x + win->evt.gap_y) / 2)) / 2);
		win->evt.dy_st = (2 * win->evt.dy_st - win->evt.dx_st) / 2;
		win->evt.dx_st = (((HEIGHT - (HEIGHT / 7)) / 2) - (((win->pos.y)
						* ((win->evt.gap_x + win->evt.gap_y) / 2)) / 2)) * 2
			- win->evt.dy_st;
	}
	else
	{
		win->evt.dx_st = (WIDTH / 2) - (((win->pos.x)
					* win->evt.gap_y) / 2);
		win->evt.dy_st = ((HEIGHT - (HEIGHT / 7)) / 2) - (((win->pos.y)
					* ((win->evt.gap_x + win->evt.gap_y) / 2)) / 2);
		win->evt.dy_st = (2 * win->evt.dy_st - win->evt.dx_st) / 2;
		win->evt.dx_st = (((HEIGHT - (HEIGHT / 7)) / 2) - (((win->pos.y)
						* ((win->evt.gap_x + win->evt.gap_y) / 2)) / 2)) * 2
			- win->evt.dy_st;
	}
}

void		ft_first_pt(t_win *win)
{
	if (win->proj == 0)
	{
		if (win->pos.x > win->pos.y)
		{
			win->evt.dx_st = (WIDTH / 2) - (win->pos.x / 4) * win->evt.gap_x;
			win->evt.dy_st = ((HEIGHT - (HEIGHT / 7)) / 2) - (win->pos.y + 1)
				* win->evt.gap_y;
		}
		else
		{
			win->evt.dx_st = (WIDTH / 2) + (win->pos.x / 4) * win->evt.gap_x;
			win->evt.dy_st = ((HEIGHT - (HEIGHT / 7)) / 2) - (win->pos.x + 1)
				* win->evt.gap_y;
		}
	}
	else
		ft_first_pt2(win);
}

static void	ft_declaration(t_win *win)
{
	ft_gap(win);
	win->dir_h = 0;
	win->dir_v = 0;
	ft_rgb_to_white(&(win->rgb));
	win->proj = 0;
	win->degrade = 0;
	win->cst_proj = 0.7;
	win->rgb.bol = 0;
	win->mark_x = 0;
	win->mark_y = HEIGHT / 14;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, "FDF");
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT - HEIGHT / 7);
	win->img_str = mlx_get_data_addr(win->img_ptr, &(win->bpp),
			&(win->s_l), &(win->endian));
	ft_first_pt(win);
}

static void	ft_create_window(t_win *win)
{
	if (WIDTH > 500 && HEIGHT > 500)
	{
		mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH / 2 - 150, HEIGHT / 2,
				0x00ff00, "PRESS '1' for parallele projection");
		mlx_string_put(win->mlx_ptr, win->win_ptr, WIDTH / 2 - 150, HEIGHT / 2
				+ 20, 0x00ff00, "PRESS '2' for isometric projection");
		mlx_string_put(win->mlx_ptr, win->win_ptr, 0, 0, 0x00ff00,
				"PRESS 'esc' to quit");
		win->proj = -1;
	}
	else
	{
		ft_fill_window_para(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img_ptr,
				win->mark_x, win->mark_y);
		ft_legends(*win);
	}
	mlx_hook(win->win_ptr, 2, 0, ft_deal_key, win);
	mlx_loop(win->mlx_ptr);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_win	win;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			exit(1);
		win.pos = ft_check_file(fd);
		if (win.pos.x == 0 || win.pos.y == 0)
			ft_usage(1);
		ft_declaration(&win);
		if (close(fd) == -1)
			exit(1);
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			exit(1);
		if ((win.pix = ft_create_map(fd, win.pos)) == 0)
			exit(1);
		if (close(fd) == -1)
			exit(1);
		ft_create_window(&win);
	}
	else
		ft_usage(2);
	return (0);
}
