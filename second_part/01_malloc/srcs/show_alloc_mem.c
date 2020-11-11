/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 08:52:31 by roster            #+#    #+#             */
/*   Updated: 2020/09/03 08:38:54 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** Compare addresses values of the three region memzone and return the little
** one. Region needs to be a memzone
*/

static t_chunk	*find_next_chunk(t_chunk **region, size_t idx)
{
	uintptr_t	prev;
	uintptr_t	next;

	prev = (idx - 1 > 2) ? (uintptr_t)region[2] : (uintptr_t)region[idx - 1];
	next = (idx + 1 > 2) ? (uintptr_t)region[0] : (uintptr_t)region[idx + 1];
	if ((!region[idx] && next) || (!region[idx] && prev))
	{
		return (find_next_chunk(region, get_region_idx(next ?
			((t_chunk*)next)->size : ((t_chunk*)prev)->size)));
	}
	if (region[idx] && prev && next)
	{
		if ((uintptr_t)region[idx] < prev && (uintptr_t)region[idx] > next)
			return ((t_chunk*)next);
		else if ((uintptr_t)region[idx] > prev && (uintptr_t)region[idx] < next)
			return ((t_chunk*)prev);
		else if ((uintptr_t)region[idx] > prev && (uintptr_t)region[idx] > next)
			return (prev > next ? (t_chunk*)next : (t_chunk*)prev);
	}
	else if (region[idx] && prev && !next && (uintptr_t)region[idx] > prev)
		return ((t_chunk*)prev);
	else if (region[idx] && !prev && next && (uintptr_t)region[idx] > next)
		return ((t_chunk*)next);
	return (region[idx]);
}

/*
** init region variable to work on a copy of g_region (to keep heads of region)
*/

static void		init_region(t_chunk **tiny, t_chunk **small, t_chunk **large,
	t_total *total)
{
	*tiny = g_region[0];
	*small = g_region[1];
	*large = g_region[2];
	total->octets = 0;
	total->allocs = 0;
	total->frees = 0;
	total->chunks = 0;
}

/*
** show_alloc_mem displays adresses of the allocated memory which is being used
** Memories area are sorted by ascending hex values.
** A total of octets is also displayed and a total of allocations number
*/

void			show_alloc_mem(void)
{
	size_t	idx;
	t_total	total;
	t_chunk	*head;
	t_chunk	*region[3];

	pthread_mutex_lock(&g_mutex);
	init_region(&region[0], &region[1], &region[2], &total);
	while ((head = find_next_chunk(region, 0)) != NULL)
	{
		print_region(head, &total);
		idx = get_region_idx(head->size);
		head = head->next;
		while (head && head->memzone == false)
		{
			print_chunk(head, &total);
			head = head->next;
		}
		region[idx] = head;
	}
	pthread_mutex_unlock(&g_mutex);
}
