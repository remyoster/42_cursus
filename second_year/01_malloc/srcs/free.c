/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:30:42 by roster            #+#    #+#             */
/*   Updated: 2020/09/03 08:55:45 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <unistd.h>
#include "malloc.h"

/*
** Unmap the memory.
** It calculates the memory length of the memzone to make unmap works.
** It unlink the memzone of the region without breaking the chain.
*/

static void	free_memzone(t_chunk **region, t_chunk *chunk, size_t mem_length)
{
	t_chunk	*tmp;
	t_chunk	*prev;

	prev = *region;
	if (prev == chunk)
	{
		*region = find_next_memzone(&chunk);
		munmap(prev, mem_length);
		pthread_mutex_unlock(&g_mutex);
		return ;
	}
	while (prev)
	{
		tmp = prev->next;
		if (tmp && tmp == chunk)
		{
			prev->next = find_next_memzone(&chunk);
			munmap(tmp, mem_length);
			pthread_mutex_unlock(&g_mutex);
			return ;
		}
		prev = prev->next;
	}
	pthread_mutex_unlock(&g_mutex);
}

static void	free_region(t_chunk **region)
{
	t_chunk	*head;
	t_chunk	*next;

	if (!(*region) || !(region))
	{
		pthread_mutex_unlock(&g_mutex);
		return ;
	}
	head = *region;
	while (head)
	{
		next = find_next_memzone(&head);
		if (next && head->status == FREE && is_memzone_free(&head))
			free_memzone(region, head,
				get_mem_length(get_chunk_size(head->size)));
		head = next;
	}
	pthread_mutex_unlock(&g_mutex);
}

/*
** Frees the memory space pointed to by ptr by finding the chunk pointed to
** by ptr and put his status to FREE.
** If the chunk is a memzone it checks if the entire memzone is free. If it is
** it calls free_region to unmap it.
*/

void		free(void *ptr)
{
	size_t	idx;
	size_t	mem_length;
	t_chunk	*chunk;

	pthread_mutex_lock(&g_mutex);
	if (ptr == NULL)
	{
		pthread_mutex_unlock(&g_mutex);
		return ;
	}
	chunk = find_chunk(ptr, &idx);
	if (chunk)
	{
		chunk->status = FREE;
		chunk->size = get_chunk_size(chunk->size);
		mem_length = get_mem_length(chunk->size);
		if (chunk->size > SMALL_CHUNK_SIZE)
			return (free_memzone(&g_region[idx], chunk, mem_length));
		else
			return (free_region(&g_region[idx]));
	}
	pthread_mutex_unlock(&g_mutex);
}
