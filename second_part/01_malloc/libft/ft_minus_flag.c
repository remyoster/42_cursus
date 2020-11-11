/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:00:54 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 09:42:14 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_put_space_at_end(char *tmp)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	k = ft_strlen(tmp);
	while (tmp[i] == ' ')
		i++;
	j = ft_strlen(tmp) - i;
	tmp = ft_strcpy(tmp, &tmp[i]);
	i = ft_strlen(tmp);
	while (j < k)
	{
		tmp[j] = ' ';
		j++;
	}
	return (tmp);
}

char		*ft_minus_flag(va_list ap, const char *fmt, t_flg *flg)
{
	char	*tmp;
	size_t	i;

	i = 0;
	flg->tab[flg->k++] = '-';
	while (fmt[flg->i + 1] == '-')
		flg->i++;
	tmp = ft_dispatcher(ap, fmt, flg);
	if (ft_strchr(flg->tab, '0') != NULL)
	{
		while (tmp[i] == '0')
			tmp[i++] = ' ';
	}
	if (tmp[0] == ' ')
		tmp = ft_put_space_at_end(tmp);
	return (tmp);
}
