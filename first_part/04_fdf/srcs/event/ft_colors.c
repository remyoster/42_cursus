/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:12:07 by roster            #+#    #+#             */
/*   Updated: 2019/02/11 19:13:43 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	ft_colors1(t_rgb *rgb)
{
	if (rgb->bol == 0)
	{
		rgb->b = -8;
		rgb->g = -8;
		rgb->r = -8;
	}
	if (rgb->bol == 1)
	{
		rgb->b = 102;
		rgb->g = 102;
		rgb->r = -1;
	}
	if (rgb->bol == 2)
	{
		rgb->b = 102;
		rgb->g = -77;
		rgb->r = -1;
	}
	if (rgb->bol == 3)
	{
		rgb->b = 102;
		rgb->g = -1;
		rgb->r = -1;
	}
}

static void	ft_colors2(t_rgb *rgb)
{
	if (rgb->bol == 4)
	{
		rgb->b = 102;
		rgb->g = -1;
		rgb->r = -77;
	}
	if (rgb->bol == 5)
	{
		rgb->b = 102;
		rgb->g = -1;
		rgb->r = 102;
	}
	if (rgb->bol == 6)
	{
		rgb->b = -77;
		rgb->g = -1;
		rgb->r = 102;
	}
	if (rgb->bol == 7)
	{
		rgb->b = -1;
		rgb->g = -1;
		rgb->r = 102;
	}
}

static void	ft_colors3(t_rgb *rgb)
{
	if (rgb->bol == 8)
	{
		rgb->b = -1;
		rgb->g = -77;
		rgb->r = 102;
	}
	if (rgb->bol == 9)
	{
		rgb->b = -1;
		rgb->g = 102;
		rgb->r = 102;
	}
	if (rgb->bol == 10)
	{
		rgb->b = -1;
		rgb->g = 102;
		rgb->r = -77;
	}
}

void		ft_colors(t_rgb *rgb)
{
	if (rgb->bol >= 0 && rgb->bol <= 3)
		ft_colors1(rgb);
	else if (rgb->bol >= 4 && rgb->bol <= 7)
		ft_colors2(rgb);
	else
		ft_colors3(rgb);
}
