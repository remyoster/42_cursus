/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accuracy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:59:12 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 11:14:38 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_acc_diouxx(char *tmp, t_flg *flg)
{
	size_t	str_width;

	str_width = ft_strlen(tmp);
	if (ft_strrchr(tmp, '-') != NULL)
		str_width--;
	if (str_width < flg->acc)
	{
		tmp = ft_realloc(tmp, (flg->acc - str_width), 1);
		ft_memset(tmp, '0', (flg->acc - str_width));
		if (ft_strrchr(tmp, '-') != NULL)
		{
			str_width = ft_strlen(tmp) - 1;
			while (tmp[str_width] != '-')
				str_width--;
			tmp[str_width] = '0';
			tmp[0] = '-';
		}
	}
	return (tmp);
}

char		*ft_accuracy(va_list ap, const char *fmt, t_flg *flg)
{
	char	*tmp;

	flg->i++;
	flg->tab[flg->k++] = '.';
	flg->acc = ft_atol(&fmt[flg->i + 1]);
	while (fmt[flg->i + 1] >= 48 && fmt[flg->i + 1] <= 57)
		flg->i++;
	if (flg->acc > 2147483647 && fmt[flg->i + 1] == 'f')
		flg->acc = 6;
	tmp = ft_dispatcher(ap, fmt, flg);
	if (flg->acc == 0 && tmp[0] == '0' && tmp[1] == '\0'
			&& ft_parse_diouxx(fmt, flg, -1) != 0)
		tmp[0] = 0;
	if (fmt[flg->i] == 's')
	{
		if (flg->acc < ft_strlen(tmp))
			tmp = ft_strsub_free(tmp, 0, flg->acc, 1);
	}
	else if (ft_parse_diouxx(fmt, flg, -1) != 0)
		tmp = ft_acc_diouxx(tmp, flg);
	flg->acc = 6;
	return (tmp);
}
