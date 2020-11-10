/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 08:43:48 by roster            #+#    #+#             */
/*   Updated: 2020/04/09 08:48:50 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned long int nb, unsigned int base)
{
	static const char str_base[] = "0123456789ABCDEF";

	if (base > 1 && base <= 16 && nb / base > 0)
		ft_putnbr_base(nb / base, base);
	ft_putchar(str_base[nb % base]);
}
