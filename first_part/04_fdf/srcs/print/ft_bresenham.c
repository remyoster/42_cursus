/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 12:48:22 by roster            #+#    #+#             */
/*   Updated: 2019/02/11 19:15:50 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_line_1(char *img_str, t_crd crd, int count)
{
	crd.e = -crd.dx;
	crd.m = 2 * crd.dy;
	while (crd.x0 <= crd.x1)
	{
		if (crd.x0 >= 0 && crd.y0 >= 0 &&
				crd.x0 < WIDTH && crd.y0 < HEIGHT - HEIGHT / 7)
		{
			ft_cmp_rgb(&crd, count);
			ft_fill_pixel(img_str, crd.x0, crd.y0, crd.rgb_pt0);
			count++;
		}
		crd.e = crd.e + crd.m;
		crd.x0++;
		if (crd.e >= 0)
		{
			if (crd.y1 > crd.y0)
				crd.y0++;
			else
				crd.y0--;
			crd.e = crd.e - 2 * crd.dx;
		}
	}
}

static void	ft_line_1bis(char *img_str, t_crd crd, int count)
{
	crd.e = -crd.dx;
	crd.m = 2 * crd.dy;
	while (crd.x0 >= crd.x1)
	{
		if (crd.x0 >= 0 && crd.y0 >= 0 &&
				crd.x0 < WIDTH && crd.y0 < HEIGHT - HEIGHT / 7)
		{
			ft_cmp_rgb(&crd, count);
			ft_fill_pixel(img_str, crd.x0, crd.y0, crd.rgb_pt0);
			count++;
		}
		crd.e = crd.e + crd.m;
		crd.x0--;
		if (crd.e >= 0)
		{
			if (crd.y1 > crd.y0)
				crd.y0++;
			else
				crd.y0--;
			crd.e = crd.e - 2 * crd.dx;
		}
	}
}

static void	ft_line_2(char *img_str, t_crd crd, int count)
{
	crd.e = -crd.dy;
	crd.m = 2 * crd.dx;
	while (crd.y0 <= crd.y1)
	{
		if (crd.x0 >= 0 && crd.y0 >= 0 &&
				crd.x0 < WIDTH && crd.y0 < HEIGHT - HEIGHT / 7)
		{
			ft_cmp_rgb(&crd, count);
			ft_fill_pixel(img_str, crd.x0, crd.y0, crd.rgb_pt0);
			count++;
		}
		crd.e = crd.e + crd.m;
		crd.y0++;
		if (crd.e >= 0)
		{
			if (crd.x1 > crd.x0)
				crd.x0++;
			else
				crd.x0--;
			crd.e = crd.e - 2 * crd.dy;
		}
	}
}

static void	ft_line_2bis(char *img_str, t_crd crd, int count)
{
	crd.e = -crd.dy;
	crd.m = 2 * crd.dx;
	while (crd.y0 >= crd.y1)
	{
		if (crd.x0 >= 0 && crd.y0 >= 0 &&
				crd.x0 < WIDTH && crd.y0 < HEIGHT - HEIGHT / 7)
		{
			ft_cmp_rgb(&crd, count);
			ft_fill_pixel(img_str, crd.x0, crd.y0, crd.rgb_pt0);
			count++;
		}
		crd.e = crd.e + crd.m;
		crd.y0--;
		if (crd.e >= 0)
		{
			if (crd.x1 > crd.x0)
				crd.x0++;
			else
				crd.x0--;
			crd.e = crd.e - 2 * crd.dy;
		}
	}
}

void		ft_bresenham(char *img_str, t_crd crd)
{
	int count;

	count = 0;
	crd.dx = ABS((crd.x1 - crd.x0));
	crd.dy = ABS((crd.y1 - crd.y0));
	if (crd.dx >= crd.dy)
	{
		if (crd.x0 < crd.x1)
			ft_line_1(img_str, crd, count);
		else
			ft_line_1bis(img_str, crd, count);
	}
	else
	{
		if (crd.y0 < crd.y1)
			ft_line_2(img_str, crd, count);
		else
			ft_line_2bis(img_str, crd, count);
	}
}
