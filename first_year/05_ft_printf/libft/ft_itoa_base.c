/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:15:28 by roster            #+#    #+#             */
/*   Updated: 2019/03/07 13:21:57 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function take any int and transform it to the corresponding base
*/

static int	ft_search_power_max(long int nb, int base)
{
	int count;
	int power;

	if (nb == 0)
		return (0);
	power = 0;
	count = 1;
	while (nb - count * ft_power(base, power) >= 0)
		power++;
	power--;
	return (power);
}

static char	*ft_fill(long int nb, int base, char *tab)
{
	int		count;
	int		power;
	size_t	i;

	count = 1;
	i = 0;
	power = ft_search_power_max(nb, base);
	while (power > -1)
	{
		while (nb - count * ft_power(base, power) >= 0)
			count++;
		count--;
		tab[i] = count + 48;
		if (count >= 10)
			tab[i] = count + 87;
		nb = nb - count * ft_power(base, power);
		count = 1;
		power--;
		i++;
	}
	return (tab);
}

char		*ft_itoa_base(int nb, int base)
{
	char			*tab;
	int				i;
	unsigned int	tmp;

	i = 0;
	tmp = nb;
	if (base <= 1 || base > 35)
		return (0);
	else if (base == 10 & nb >= 0)
		return (ft_uitoa(nb));
	else if (base == 10 && nb < 0)
		return (ft_itoa(nb));
	tab = ft_strnew(64);
	if (nb < 0)
		return (ft_fill(tmp, base, tab));
	return (ft_fill(nb, base, tab));
}
