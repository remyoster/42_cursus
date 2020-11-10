/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 08:52:14 by roster            #+#    #+#             */
/*   Updated: 2020/09/03 08:05:49 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** Allocate size bytes of memory and return a pointer on the allocated zone.
** It gets the region index of where the future chunk or mmap is going
** to be linked. Then it search if the region has free space left. If it does
** a pointer to the chunk is returned, his size and status are changed and the
** a pointer to his available memory(chunk + sizeof(chunk)) is returned.
** If the region doesn't exist yet or hasn't free space left, it calls init_mem
** to get a new chunk list and add it to the corresponding region.
*/

t_chunk *g_region[3] = {NULL, NULL, NULL};
pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

void	*malloc(size_t size)
{
	t_chunk	*chunk;
	size_t	idx_region;

	pthread_mutex_lock(&g_mutex);
	idx_region = get_region_idx(size);
	chunk = search_free_chunk(&g_region[idx_region], idx_region);
	if (!chunk)
	{
		chunk = init_mem(size);
		if (!chunk)
			return (NULL);
		add_region(&g_region[idx_region], &chunk);
	}
	else
	{
		chunk->size = size;
		chunk->status = USED;
	}
	pthread_mutex_unlock(&g_mutex);
	return ((void *)((uintptr_t)chunk + sizeof(t_chunk)));
}
