/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_legends.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:02:32 by roster            #+#    #+#             */
/*   Updated: 2019/02/11 19:16:57 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../../includes/fdf.h"

static void	ft_put_legends_right(t_win win)
{
	int	c;

	c = 0xd9d9d9;
	if (HEIGHT > 800 && WIDTH > 800)
	{
		mlx_string_put(win.mlx_ptr, win.win_ptr, WIDTH - 250, 120, c,
				"Move : W A S D");
		mlx_string_put(win.mlx_ptr, win.win_ptr, WIDTH - 250, 160, c,
				"Recenter : TAB");
		mlx_string_put(win.mlx_ptr, win.win_ptr, WIDTH - 250, 200, c,
				"Change colors: { }");
		mlx_string_put(win.mlx_ptr, win.win_ptr, WIDTH - 250, 240, c,
				"Apply a degrade: space");
		mlx_string_put(win.mlx_ptr, win.win_ptr, WIDTH - 250, 280, c,
				"Change projection: p");
	}
}

static void	ft_put_legends_left(t_win win, void *band_ptr)
{
	int c;

	c = 0xd9d9d9;
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, band_ptr, 0, 0);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, band_ptr, 0,
				HEIGHT - HEIGHT / 14);
	if (HEIGHT > 800 && WIDTH > 800)
	{
		mlx_string_put(win.mlx_ptr, win.win_ptr, 10, 120, c, "Zoom in : +");
		mlx_string_put(win.mlx_ptr, win.win_ptr, 10, 140, c, "Zoom out : -");
		mlx_string_put(win.mlx_ptr, win.win_ptr, 10, 180, c, "Altitude + : >");
		mlx_string_put(win.mlx_ptr, win.win_ptr, 10, 200, c, "Altitude - : <");
	}
}

void		ft_legends(t_win win)
{
	int		x;
	int		y;
	t_win	band;
	void	*band_ptr;
	char	*band_str;

	band_ptr = mlx_new_image(win.mlx_ptr, WIDTH, HEIGHT / 14);
	band_str = mlx_get_data_addr(band_ptr, &(band.bpp),
			&(band.s_l), &(band.endian));
	y = 0;
	while (y < HEIGHT / 14)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_fill_pixel(band_str, x, y, win.rgb);
			x++;
		}
		y++;
	}
	ft_put_legends_left(win, band_ptr);
	ft_put_legends_right(win);
}
