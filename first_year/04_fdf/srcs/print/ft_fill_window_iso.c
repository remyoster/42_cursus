/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_window_iso.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:37:14 by roster            #+#    #+#             */
/*   Updated: 2019/02/11 19:16:20 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_do_the_math2(t_win *win, t_crd *crd, size_t i, size_t j)
{
	while (i < win->pos.y - 1)
	{
		crd->x0 = win->evt.dx - win->evt.dy;
		crd->y0 = win->cst_proj * win->pix[i][j].z * (-win->evt.gap_y) / 5
			+ win->evt.dx / 2 + win->evt.dy / 2;
		if (win->pix[i][j].h > -1)
			ft_hexa_to_rgb(win->pix[i][j].h, &(crd->rgb_pt0));
		else
			crd->rgb_pt0 = win->rgb;
		win->evt.dx = win->evt.dx - win->evt.gap_x;
		win->evt.dy = win->evt.dy + win->evt.gap_y;
		crd->x1 = win->evt.dx - win->evt.dy;
		crd->y1 = win->cst_proj * win->pix[i + 1][j].z * (-win->evt.gap_y) / 5
			+ win->evt.dx / 2 + win->evt.dy / 2;
		if (win->pix[i + 1][j].h > -1)
			ft_hexa_to_rgb(win->pix[i + 1][j].h, &(crd->rgb_pt1));
		else
			crd->rgb_pt1 = win->rgb;
		ft_bresenham(win->img_str, *crd);
		i++;
	}
}

static void	ft_fill_window_iso_part2(t_win *win)
{
	size_t	i;
	size_t	j;
	t_crd	crd;

	win->evt.dx = win->evt.dx_st;
	win->evt.dy = win->evt.dy_st;
	j = 0;
	while (j < win->pos.x)
	{
		i = 0;
		ft_do_the_math2(win, &crd, i, j);
		j++;
		win->evt.dx = win->evt.dx + (win->pos.y) * win->evt.gap_x;
		win->evt.dy = win->evt.dy - (win->pos.y - 2) * win->evt.gap_y;
	}
}

static void	ft_do_the_math(t_win *win, t_crd *crd, size_t i, size_t j)
{
	while (j < win->pos.x - 1)
	{
		crd->x0 = win->evt.dx - win->evt.dy;
		crd->y0 = win->cst_proj * win->pix[i][j].z * (-win->evt.gap_y) / 5
			+ win->evt.dx / 2 + win->evt.dy / 2;
		if (win->pix[i][j].h > -1)
			ft_hexa_to_rgb(win->pix[i][j].h, &(crd->rgb_pt0));
		else
			crd->rgb_pt0 = win->rgb;
		win->evt.dx = win->evt.dx + win->evt.gap_x;
		win->evt.dy = win->evt.dy + win->evt.gap_y;
		crd->x1 = win->evt.dx - win->evt.dy;
		crd->y1 = win->cst_proj * win->pix[i][j + 1].z * (-win->evt.gap_y) / 5
			+ win->evt.dx / 2 + win->evt.dy / 2;
		if (win->pix[i][j + 1].h > -1)
			ft_hexa_to_rgb(win->pix[i][j + 1].h, &(crd->rgb_pt1));
		else
			crd->rgb_pt1 = win->rgb;
		ft_bresenham(win->img_str, *crd);
		j++;
	}
}

void		ft_fill_window_iso(t_win *win)
{
	size_t	i;
	size_t	j;
	t_crd	crd;

	win->evt.dx = win->evt.dx_st;
	win->evt.dy = win->evt.dy_st;
	i = 0;
	while (i < win->pos.y)
	{
		j = 0;
		ft_do_the_math(win, &crd, i, j);
		i++;
		win->evt.dx = win->evt.dx - (win->pos.x) * win->evt.gap_x;
		win->evt.dy = win->evt.dy - (win->pos.x - 2) * win->evt.gap_y;
	}
	ft_fill_window_iso_part2(win);
}
