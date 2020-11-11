/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:31:00 by roster            #+#    #+#             */
/*   Updated: 2019/02/11 19:09:59 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../includes/fdf.h"

static void	ft_cmp_1(int *a, int *b, int hypo, int count)
{
	static int res;

	if (hypo >= (*a - *b))
	{
		if ((count % (hypo / (*a - *b))) == 0)
			*a = *a - 1;
	}
	else
	{
		if (count == 0)
			res = ((*a - *b) / hypo);
		*a = *a - res;
	}
}

static void	ft_cmp_2(int *a, int *b, int hypo, int count)
{
	static int res;

	if (hypo >= (*b - *a))
	{
		if ((count % (hypo / (*b - *a))) == 0)
			*a = *a + 1;
	}
	else
	{
		if (count == 0)
			res = ((*b - *a) / hypo);
		*a = *a + res;
	}
}

void		ft_cmp_rgb(t_crd *crd, int count)
{
	int	hypo;

	hypo = hypot(crd->dx, crd->dy);
	if (crd->rgb_pt0.r > crd->rgb_pt1.r)
		ft_cmp_1(&(crd->rgb_pt0.r), &(crd->rgb_pt1.r), hypo, count);
	else if (crd->rgb_pt0.r < crd->rgb_pt1.r)
		ft_cmp_2(&(crd->rgb_pt0.r), &(crd->rgb_pt1.r), hypo, count);
	if (crd->rgb_pt0.g > crd->rgb_pt1.g)
		ft_cmp_1(&(crd->rgb_pt0.g), &(crd->rgb_pt1.g), hypo, count);
	else if (crd->rgb_pt0.g < crd->rgb_pt1.g)
		ft_cmp_2(&(crd->rgb_pt0.g), &(crd->rgb_pt1.g), hypo, count);
	if (crd->rgb_pt0.b > crd->rgb_pt1.b)
		ft_cmp_1(&(crd->rgb_pt0.b), &(crd->rgb_pt1.b), hypo, count);
	else if (crd->rgb_pt0.b < crd->rgb_pt1.b)
		ft_cmp_2(&(crd->rgb_pt0.b), &(crd->rgb_pt1.b), hypo, count);
}
