/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_to_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 07:43:06 by roster            #+#    #+#             */
/*   Updated: 2019/02/11 19:22:57 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include "../../libft/libft.h"

void		ft_rgb_to_white(t_rgb *rgb)
{
	rgb->r = 247;
	rgb->g = 247;
	rgb->b = 247;
}

static void	ft_reset_rgb(t_rgb *rgb)
{
	rgb->r = 0;
	rgb->b = 0;
	rgb->g = 0;
}

void		ft_int_to_char(t_rgb *rgb)
{
	if (rgb->r > 127)
		rgb->r = rgb->r - 256;
	if (rgb->g > 127)
		rgb->g = rgb->g - 256;
	if (rgb->b > 127)
		rgb->b = rgb->b - 256;
}

void		ft_hexa_to_rgb(int res, t_rgb *rgb)
{
	size_t i;

	ft_reset_rgb(rgb);
	i = 0;
	while (res)
	{
		if (i >= 16 && i <= 23)
			if (res & 1)
				rgb->r = rgb->r + ft_power(2, (i - 16));
		if (i >= 8 && i <= 15)
			if (res & 1)
				rgb->g = rgb->g + ft_power(2, (i - 8));
		if (i <= 7)
			if (res & 1)
				rgb->b = rgb->b + ft_power(2, i);
		i++;
		res >>= 1;
	}
}

int			ft_rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
