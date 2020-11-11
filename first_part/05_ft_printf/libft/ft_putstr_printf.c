/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:57:14 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 15:51:30 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char		*ft_printf_error(va_list ap, t_flg *flg)
{
	char	*tmp;

	flg->i++;
	tmp = va_arg(ap, char *);
	return (ft_strdup(""));
}

static void	ft_print_normal(char *s, t_flg *flg)
{
	if (ft_strchr(flg->tab, '1') != NULL)
	{
		if (ft_strchr(flg->tab, '@') != NULL
				&& ft_strchr(flg->tab, '-') == NULL)
		{
			ft_putstr_free(s);
			ft_putchar(0);
			flg->count++;
		}
		else if (ft_strchr(flg->tab, '@') != NULL
				&& ft_strchr(flg->tab, '-') != NULL)
		{
			ft_putchar(0);
			ft_putstr_free(s);
			flg->count++;
		}
		else
			ft_putstr_free(s);
	}
	else
		ft_putstr_free(s);
}

int			ft_putstr_printf(char *s, t_flg *flg)
{
	flg->count = flg->count + ft_strlen(s) + ft_strlen(flg->buff);
	if (flg->count > 2147483647)
		return (-1);
	ft_putstr(flg->buff);
	if (ft_strchr(flg->tab, 'c') != NULL)
	{
		if (ft_strlen(s) == 0)
		{
			ft_putchar(0);
			flg->count++;
			ft_strdel(&s);
		}
		else
			ft_print_normal(s, flg);
	}
	else
		ft_putstr_free(s);
	ft_strclr(flg->tab);
	ft_strclr(flg->buff);
	flg->k = 0;
	return (0);
}
