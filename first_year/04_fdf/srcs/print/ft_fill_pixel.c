/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:58:51 by roster            #+#    #+#             */
/*   Updated: 2019/02/11 19:16:04 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_fill_pixel(char *img_str, int x, int y, t_rgb rgb)
{
	int i;
	int j;
	int k;
	int bol;

	bol = 0;
	i = 0 + 4 * x;
	j = 0 + 4 * WIDTH * y;
	k = i + j;
	ft_int_to_char(&rgb);
	while (bol < 4)
	{
		if (bol == 0)
			img_str[k] = rgb.b;
		if (bol == 1)
			img_str[k] = rgb.g;
		if (bol == 2)
			img_str[k] = rgb.r;
		k++;
		bol++;
	}
}
