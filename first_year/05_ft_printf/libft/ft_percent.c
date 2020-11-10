/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:10:11 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 09:41:31 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*ft_percent(t_flg *flg)
{
	char	*tmp;

	if (!(tmp = (char*)malloc(sizeof(char) * 2)))
		exit(1);
	tmp[0] = '%';
	tmp[1] = '\0';
	flg->i++;
	return (tmp);
}
