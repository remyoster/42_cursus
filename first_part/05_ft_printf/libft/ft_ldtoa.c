/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 07:02:06 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 14:53:13 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_mantisse(char *m, size_t i)
{
	while (m[i])
	{
		if (m[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_mantisse_float(char *m, int res, int i)
{
	char *new_m;

	if (res < 0)
	{
		new_m = ft_strsub(m, i, ft_strlen(m) - i);
		while (res < -1)
		{
			new_m = ft_strjoin_free("0", new_m, 2);
			res++;
		}
	}
	else
	{
		if ((int)ft_strlen(m) - i - res - 1 > 0)
			new_m = ft_strsub(m, i + res + 1, (int)ft_strlen(m) - i - res - 1);
		else
			new_m = ft_strnew(1);
	}
	return (ft_str_mantisse_to_nb(new_m, 1));
}

static void	ft_mantisse_int(char *m, char **str_res, int res, int i)
{
	if (res < 0)
	{
		*str_res = ft_strnew(1);
		(*str_res)[0] = '0';
	}
	else
	{
		*str_res = ft_strnew(res + 1);
		while (m[i] != '\0' && (i - 16) <= res)
		{
			(*str_res)[i - 16] = m[i];
			i++;
		}
		while (i - 16 <= res)
		{
			(*str_res)[i - 16] = '0';
			i++;
		}
		*str_res = ft_str_binary_to_nb(*str_res, 1);
	}
}

static char	*ft_deal_mantisse(char *m)
{
	int		i;
	int		res;
	char	*str_res;

	i = 1;
	res = 0;
	while (i < 16)
	{
		if (m[i] == '1')
			res = res + ft_power(2, 15 - i);
		i++;
	}
	if (res == 32767)
	{
		if (ft_check_mantisse(m, i) == 1)
			return (ft_strdup("nan"));
		else
			return (ft_strdup("inf"));
	}
	res = res - 16383;
	ft_mantisse_int(m, &str_res, res, i);
	str_res = ft_strjoin_free(str_res, ".", 1);
	str_res = ft_strjoin_free(str_res, ft_mantisse_float(m, res, i), 0);
	return (str_res);
}

char		*ft_ldtoa(long double ld)
{
	unsigned char	*tmp;
	size_t			i;
	char			*m;
	char			*str_res;
	char			*m_tmp;

	tmp = (unsigned char *)(&ld);
	i = 0;
	m = ft_strnew(1);
	while (i < 10)
	{
		m_tmp = ft_itoa_base(tmp[i], 2);
		while (ft_strlen(m_tmp) < 8)
			m_tmp = ft_strjoin_free("0", m_tmp, 2);
		m = ft_strjoin_free(m_tmp, m, 0);
		i++;
	}
	str_res = ft_deal_mantisse(m);
	if (m[0] == '1' && str_res[0] != 'n')
		str_res = ft_strjoin_free("-", str_res, 2);
	ft_strdel(&m);
	return (str_res);
}
