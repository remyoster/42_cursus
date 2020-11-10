/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:46:18 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 11:15:42 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*ft_0_flg(char *tmp, t_flg *flg)
{
	size_t i;

	i = 1;
	if (ft_strchr(flg->tab, ' ') == NULL)
		i = 0;
	while (tmp[i] == ' ')
	{
		tmp[i] = '0';
		i++;
	}
	if (i >= 1 && (tmp[i] == '-' || tmp[i] == '+'))
	{
		tmp[0] = tmp[i];
		tmp[i] = '0';
	}
	return (tmp);
}

static char	*ft_nb_flg(char *tmp, const char *fmt, t_flg *flg, long int width)
{
	long int	str_width;

	str_width = (long int)ft_strlen(tmp);
	if (tmp[0] == 0 && fmt[flg->i] == 'c')
		str_width = 1;
	if (str_width < width)
	{
		tmp = ft_realloc(tmp, (width - str_width), 1);
		ft_memset(tmp, ' ', (width - str_width));
	}
	if (ft_strchr(flg->tab, '0') != NULL)
	{
		if (ft_parse_diouxx(fmt, flg, -1) != 0
				&& ft_strchr(flg->tab, '.') != NULL)
			return (tmp);
		return (ft_0_flg(tmp, flg));
	}
	else
		return (tmp);
}

char		*ft_number_flag(va_list ap, const char *fmt, t_flg *flg)
{
	long int	width;
	char		*tmp;

	flg->tab[flg->k++] = '1';
	if (fmt[flg->i + 1] == '0')
		flg->tab[flg->k++] = '0';
	width = ft_atol(&fmt[flg->i + 1]);
	while (fmt[flg->i + 1] >= 48 && fmt[flg->i + 1] <= 57)
		flg->i++;
	if (width > 2147463647 || width < 0)
		return (ft_printf_error(ap, flg));
	tmp = ft_dispatcher(ap, fmt, flg);
	return (ft_nb_flg(tmp, fmt, flg, width));
}
