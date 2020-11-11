/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 11:43:54 by roster            #+#    #+#             */
/*   Updated: 2020/03/13 07:50:05 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Bool function to determine if the character is printable (32-126 ASCII)
*/

int		ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
