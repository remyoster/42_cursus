/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:54:34 by roster            #+#    #+#             */
/*   Updated: 2019/01/10 14:09:42 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

void	ft_usage(int bol)
{
	if (bol >= 3)
	{
		ft_putendl("Error : Too many arguments");
		ft_putendl("usage: ./fillit [file]");
		exit(1);
	}
	else if (bol == 1)
	{
		ft_putendl("Error : missing argument");
		ft_putendl("usage: ./fillit [file]");
		exit(1);
	}
	else if (bol == -1)
	{
		ft_putendl("error");
		exit(1);
	}
}
