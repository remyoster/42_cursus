/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashtag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:26:09 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 14:46:43 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_put_dot_end(char *tmp)
{
	size_t i;

	i = 0;
	while (tmp[i])
	{
		tmp[i] = tmp[i + 1];
		i++;
	}
	tmp[i - 1] = '.';
	return (tmp);
}

static char	*ft_deal_sp_0(char *tmp, t_flg *flg, int bol)
{
	size_t i;

	i = 0;
	if (tmp[0] == '0')
	{
		if (ft_strchr_count(tmp, '0') == 1)
			tmp = ft_strjoin_free(tmp, ".", 1);
		else
			tmp = ft_put_dot_end(tmp);
	}
	else if (tmp[0] == ' ')
		tmp = ft_put_dot_end(tmp);
	if (ft_strchr(flg->tab, ' ') != NULL && bol != '-' && bol != '+')
	{
		if (tmp[1] == '0')
			tmp[0] = ' ';
		else
			tmp = ft_strjoin_free(" ", tmp, 2);
		tmp[ft_strlen(tmp) - 1] = '.';
	}
	return (tmp);
}

static char	*ft_hash_float(char *tmp, t_flg *flg)
{
	int		bol;
	size_t	i;

	i = 0;
	bol = 0;
	if (tmp[0] == ' ' || (tmp[0] == '0' && ft_strlen(tmp) > 1))
		return (ft_deal_sp_0(tmp, flg, bol));
	else if ((tmp[0] == '-' || tmp[0] == '+') && tmp[1] == '0' && tmp[2] == '0')
	{
		bol = tmp[0];
		tmp[0] = '0';
		tmp = ft_deal_sp_0(tmp, flg, bol);
		tmp[0] = bol;
	}
	else if (ft_strchr(tmp, ' ') != NULL)
	{
		while (tmp[i] != ' ')
			i++;
		tmp[i] = '.';
	}
	else
		tmp = ft_strjoin_free(tmp, ".", 1);
	return (tmp);
}

char		*ft_hashtag(va_list ap, const char *fmt, t_flg *flg)
{
	size_t	i;
	char	*tmp;

	while (fmt[flg->i + 1] == '#')
		flg->i++;
	tmp = ft_dispatcher(ap, fmt, flg);
	i = 0;
	if (fmt[flg->i] == 'o' || fmt[flg->i] == 'x' || fmt[flg->i] == 'X')
	{
		while (tmp[i] == ' ' || tmp[i] == '0')
			i++;
		if (i == ft_strlen(tmp) && fmt[flg->i] != 'o')
			return (tmp);
		else
			return (ft_hash_oxx(tmp, flg, fmt));
	}
	else if (fmt[flg->i] == 'f')
		if (ft_strchr(tmp, '.') == NULL)
			return (ft_hash_float(tmp, flg));
	return (tmp);
}
