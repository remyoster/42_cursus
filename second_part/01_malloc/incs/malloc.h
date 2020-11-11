/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 09:51:36 by roster            #+#    #+#             */
/*   Updated: 2020/09/03 08:05:38 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

/*
** for respectively bool, uintptr_t, size_t types and pthread
*/

# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <pthread.h>

/*
** TINY_CHUNK_SIZE and SMALL_CHUNK_SIZE are constant to determines how the
** maped memory will be allocated and sliced, in which region it will be added..
** FREE and USED describe the status of a memory chunk
*/

# define TINY_CHUNK_SIZE 64
# define SMALL_CHUNK_SIZE 1024
# define REGION_SIZE 100
# define FREE 0
# define USED 1

/*
** chunk chain to map the memory
** status is either FREE or USED
** memzone tell if the chunk is the beginning of a new memzone (mmap-ed)
** size hold the used size of the chunk
*/

typedef struct		s_chunk
{
	int				status;
	bool			memzone;
	size_t			size;
	struct s_chunk	*next;

}					t_chunk;

/*
** Total struct for printing purpose :
** - octets is the number of octets allocated
** - allocs is the number of allocation made
** - frees is the number of free chunks
** - chunks is the number of chunks
*/

typedef struct		s_total
{
	size_t			octets;
	size_t			allocs;
	size_t			frees;
	size_t			chunks;
}					t_total;

/*
** Global variable to keep track of memzones.
** 0 for tiny, 1 for small, 2 for large
** And mutex global variable for threading
*/

extern t_chunk			*g_region[3];
extern pthread_mutex_t	g_mutex;

/*
** Memory functions
*/

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				*calloc(size_t nmemb, size_t size);
void				show_alloc_mem();

/*
** Utils functions
*/

size_t				get_region_idx(size_t size);
size_t				get_chunk_size(size_t size);
size_t				get_mem_length(size_t size);
t_chunk				*init_mem(size_t size);
t_chunk				*find_chunk(void *ptr, size_t *idx);

/*
** Lists manipulation functions
*/

void				add_region(t_chunk **alst, t_chunk **new);
t_chunk				*search_free_chunk(t_chunk **region, size_t idx_region);
t_chunk				*find_next_memzone(t_chunk **memzone);
bool				is_memzone_free(t_chunk **memzone);

/*
** Print functions
*/

void				print_chunk(t_chunk *chunk, t_total *total);
void				print_region(t_chunk *chunk, t_total *total);
void				print_total(t_total total);

#endif
