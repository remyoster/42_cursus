/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:10:42 by roster            #+#    #+#             */
/*   Updated: 2019/02/11 19:22:35 by lojesu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../libft/libft.h"

void	ft_usage(int bol)
{
	if (bol == 1)
	{
		ft_putendl("Invalid map file");
		exit(1);
	}
	else if (bol == 2)
	{
		ft_putendl("usage: ./fdf [file]");
		ft_putendl("[file] = any_file.fdf");
		exit(1);
	}
	else
		exit(1);
}
