/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 08:13:33 by roster            #+#    #+#             */
/*   Updated: 2020/09/01 09:26:07 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Print one char
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
