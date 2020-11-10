/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_degrade.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lojesu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 15:46:23 by lojesu            #+#    #+#             */
/*   Updated: 2019/02/11 19:14:11 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_degrade(t_win win, size_t degrade)
{
	if (degrade == 0)
		ft_colors(&(win.rgb));
	if (degrade == 1)
		ft_mountain(win);
	if (degrade == 2)
		ft_rainbow(win);
	if (degrade == 3)
		ft_reverse_rainbow(win);
}
