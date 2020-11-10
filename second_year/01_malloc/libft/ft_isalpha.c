/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 11:13:52 by roster            #+#    #+#             */
/*   Updated: 2020/03/13 07:48:45 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Bool function to determine if the character is alphabetic
*/

int		ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
