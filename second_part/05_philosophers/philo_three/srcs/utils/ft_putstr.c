/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 08:16:44 by roster            #+#    #+#             */
/*   Updated: 2020/09/01 09:02:14 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <unistd.h>

/*
** Print a string in stdout
*/

void	ft_putstr(const char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}
