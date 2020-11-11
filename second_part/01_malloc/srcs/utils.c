/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 09:26:23 by roster            #+#    #+#             */
/*   Updated: 2020/09/02 14:50:22 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <unistd.h>
#include "malloc.h"

/*
** get the g_region index 0 for tiny, 1 for small, 2 for large
*/

size_t		get_region_idx(size_t size)
{
	if (size <= TINY_CHUNK_SIZE)
		return (0);
	else if (size <= SMALL_CHUNK_SIZE)
		return (1);
	return (2);
}

/*
** get the max chunk size possible based on size (to calculate memory length)
*/

size_t		get_chunk_size(size_t size)
{
	if (size <= TINY_CHUNK_SIZE)
		return (TINY_CHUNK_SIZE);
	else if (size <= SMALL_CHUNK_SIZE)
		return (SMALL_CHUNK_SIZE);
	return (size);
}

/*
** Calculate the memory length which is going to be maped or unmaped. As we put
** some meta information on the struct we need to add theese in calcul
*/

size_t		get_mem_length(size_t size)
{
	size_t	psize;

	psize = getpagesize();
	if (size <= SMALL_CHUNK_SIZE)
	{
		return ((((size_t)REGION_SIZE * (size + sizeof(t_chunk))) / psize)
				* psize + psize);
	}
	return (((size + sizeof(t_chunk)) / psize) * psize + psize);
}

/*
** Slice a mmap zone with chunk_size to create a chunk list. It itialize each
** chunk with status FREE, and size equal to chunk_size and memzone to false
** (except for the first one). If chunk_size is large it doesn't slice the mmap.
*/

static void	slice_mem(void **addr, size_t chunk_size, size_t mem_length)
{
	t_chunk	*chunk;
	size_t	t_chunk_size;
	bool	init;

	init = true;
	t_chunk_size = chunk_size + sizeof(t_chunk);
	chunk = (t_chunk*)(*addr);
	while (mem_length > t_chunk_size && chunk)
	{
		chunk->size = chunk_size;
		chunk->status = init ? USED : FREE;
		chunk->memzone = init ? true : false;
		mem_length -= t_chunk_size;
		if (mem_length > t_chunk_size && chunk_size <= SMALL_CHUNK_SIZE)
			chunk->next = (t_chunk*)((uintptr_t)chunk + t_chunk_size);
		else
			chunk->next = NULL;
		chunk = chunk->next;
		if (init)
			init = false;
	}
}

/*
** Return a sliced mmap region (or just a mmap region)
** To do that it calculates the mem_length which is going to be required, it
** calls mmap to get a memory area and slice it based on chunk_size
*/

t_chunk		*init_mem(size_t size)
{
	size_t	mem_length;
	size_t	chunk_size;
	void	*addr;

	chunk_size = get_chunk_size(size);
	mem_length = get_mem_length(chunk_size);
	if ((addr = mmap(NULL, mem_length, PROT_READ | PROT_WRITE,
			MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
		return (NULL);
	slice_mem(&addr, chunk_size, mem_length);
	if (chunk_size <= SMALL_CHUNK_SIZE)
		((t_chunk*)addr)->size = size;
	return (addr);
}
