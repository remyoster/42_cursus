/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 08:52:21 by roster            #+#    #+#             */
/*   Updated: 2020/09/03 08:38:59 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

/*
** If the chunk has space left it updates his size value with the new size and
** return the ptr. If there is no space left it calls malloc to have a new
** chunk and copy data from old chunk to new chunk
*/

static void	*toggle_realloc(t_chunk **chunk, void *ptr, size_t size,
		size_t idx_region)
{
	t_chunk	*new;

	new = NULL;
	if ((idx_region < 2
				&& (size + (*chunk)->size) <= get_chunk_size((*chunk)->size))
			|| (idx_region == 2
				&& (size + (*chunk)->size) <= get_mem_length((*chunk)->size)))
	{
		(*chunk)->size += size;
		pthread_mutex_unlock(&g_mutex);
		return (ptr);
	}
	else
	{
		pthread_mutex_unlock(&g_mutex);
		if (!(new = malloc(size + (*chunk)->size)))
			return (ptr);
		ft_memmove(new, ptr, (*chunk)->size);
		free(ptr);
		return (new);
	}
}

/*
** Change the size of the memory block pointed to by ptr to size
** It located the chunk in the good memzone and call toggle_realloc to check
** if it can be changed.
*/

void		*realloc(void *ptr, size_t size)
{
	size_t	idx;
	t_chunk	*chunk;

	pthread_mutex_lock(&g_mutex);
	if (!ptr)
	{
		pthread_mutex_unlock(&g_mutex);
		return (malloc(size));
	}
	else if (size == 0)
	{
		pthread_mutex_unlock(&g_mutex);
		free(ptr);
		return (NULL);
	}
	chunk = find_chunk(ptr, &idx);
	if (chunk)
		return (toggle_realloc(&chunk, ptr, size, idx));
	pthread_mutex_unlock(&g_mutex);
	return (NULL);
}
