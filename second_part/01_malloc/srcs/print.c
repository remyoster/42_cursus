/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 07:48:03 by roster            #+#    #+#             */
/*   Updated: 2020/09/03 08:56:00 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

/*
** print the address of the memory used by a chunk (begin - end), print
** total octets used by that chunk and add it to total
*/

void	print_chunk(t_chunk *chunk, t_total *total)
{
	total->chunks += 1;
	if (chunk->status != USED)
	{
		total->frees += 1;
		return ;
	}
	ft_putstr("0X");
	ft_putnbr_base((uintptr_t)chunk + sizeof(t_chunk), 16);
	ft_putstr(" - ");
	ft_putstr("0X");
	ft_putnbr_base((uintptr_t)chunk + sizeof(t_chunk) + chunk->size, 16);
	ft_putstr(" : ");
	ft_putnbr_base(chunk->size, 10);
	ft_putstr(" octets\n");
	total->octets += chunk->size;
	total->allocs += 1;
}

/*
** Display the region type and the base adress of it.
** chunk needs to be a memzone
*/

void	print_region(t_chunk *chunk, t_total *total)
{
	if (!chunk)
		return ;
	if (chunk->size <= TINY_CHUNK_SIZE)
		ft_putstr("TINY  : ");
	else if (chunk->size <= SMALL_CHUNK_SIZE)
		ft_putstr("SMALL : ");
	else
		ft_putstr("LARGE : ");
	ft_putstr("0X");
	ft_putnbr_base((uintptr_t)chunk, 16);
	ft_putchar('\n');
	print_chunk(chunk, total);
}

/*
** Print the total allocation stats
*/

void	print_total(t_total total)
{
	ft_putstr("Total : ");
	ft_putnbr_base(total.octets, 10);
	ft_putstr(" octets - ");
	ft_putnbr_base(total.allocs, 10);
	ft_putstr(" allocations - ");
	ft_putnbr_base(total.frees, 10);
	ft_putchar('/');
	ft_putnbr_base(total.chunks, 10);
	ft_putstr(" free chunk spaces\n");
}
