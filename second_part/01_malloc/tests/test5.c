/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 09:56:44 by roster            #+#    #+#             */
/*   Updated: 2020/09/03 08:53:02 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/malloc.h"

/*
** Test show_alloc_mem
*/

int	main(void)
{
	char	*str;

	str = malloc(64);
	str = malloc(1024);
	str = malloc(1024 * 32);
	str = malloc(1024 * 1024);
	str = malloc(1024 * 1024 * 16);
	str = malloc(1024 * 1024 * 128);
	show_alloc_mem();
	return (0);
}
