/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_binary_to_nb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 10:42:12 by roster            #+#    #+#             */
/*   Updated: 2019/03/05 10:15:03 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function transform any binary string to a string number
** The mod is use to free the binary if needed
*/

static int	ft_protection(char *bin)
{
	size_t	i;

	i = 0;
	while (bin[i])
	{
		if (bin[i] != '1' && bin[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

char		*ft_str_binary_to_nb(char *bin, int mod)
{
	int		i;
	int		j;
	char	*res;

	if (!bin || ft_protection(bin) == 0)
		return (0);
	res = ft_strnew(1);
	res[0] = '0';
	i = 0;
	j = ft_strlen(bin) - 1;
	while (bin[i])
	{
		if (bin[i] == '1')
			res = ft_add_str(res, ft_power_str((j - i), 2), 3);
		i++;
	}
	if (mod == 1)
		ft_strdel(&bin);
	return (res);
}
