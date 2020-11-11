/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:05:44 by roster            #+#    #+#             */
/*   Updated: 2019/02/13 12:59:25 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_gap(t_win *win)
{
	int i;

	i = 0;
	win->evt.gap_y = 40;
	while (win->evt.gap_y * win->pos.y > HEIGHT ||
			2 * win->evt.gap_y * win->pos.x > WIDTH)
	{
		win->evt.gap_y--;
		if (win->evt.gap_y == 1)
			break ;
	}
	if (i == 0 && win->evt.gap_y == 40)
	{
		while (win->evt.gap_y * win->pos.y < HEIGHT - HEIGHT / 7 ||
				2 * win->evt.gap_y * win->pos.x < WIDTH)
		{
			win->evt.gap_y++;
			i++;
			if (win->evt.gap_y == 1 || i > 138)
				break ;
		}
		win->evt.gap_y = ABS((40 - i));
	}
	win->evt.gap_x = win->evt.gap_y * 2;
}
