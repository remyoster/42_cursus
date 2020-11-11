/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 08:52:05 by roster            #+#    #+#             */
/*   Updated: 2020/09/03 08:56:13 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** utils functions :
** - add_region : Add the new memzone to g_region[idx]
** - search_free_chunk : search a free space (chunk) in the region or NULL
** - find_next_memzone : find the next memzone (chunk->memzone) in a region
** - is_memzone_free : check if the entire memzone is free
** - find_chunk : find the chunk pointed to by ptr or NULL
*/

void		add_region(t_chunk **alst, t_chunk **new)
{
	t_chunk	*tmp;

	if (!(new))
		return ;
	if (!(alst) || !(*alst))
	{
		*alst = *new;
		return ;
	}
	tmp = *new;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *alst;
	*alst = *new;
}

t_chunk		*search_free_chunk(t_chunk **region, size_t idx_region)
{
	t_chunk	*head;

	if (idx_region == 2)
		return (NULL);
	head = *region;
	while (head)
	{
		if (head->status == FREE)
			return (head);
		head = head->next;
	}
	return (head);
}

t_chunk		*find_next_memzone(t_chunk **memzone)
{
	t_chunk	*head;

	if (!(*memzone) || !(memzone))
		return (NULL);
	head = (*memzone)->next;
	while (head && head->memzone == false)
		head = head->next;
	return (head);
}

bool		is_memzone_free(t_chunk **memzone)
{
	t_chunk	*head;

	if (!(*memzone) || !(memzone))
		return (false);
	head = (*memzone)->next;
	while (head && head->memzone == false)
	{
		if (head->status == USED)
			return (false);
		head = head->next;
	}
	return (true);
}

t_chunk		*find_chunk(void *ptr, size_t *idx)
{
	t_chunk *chunk;

	*idx = 0;
	while (*idx < 3)
	{
		chunk = g_region[*idx];
		while (chunk)
		{
			if ((uintptr_t)chunk + sizeof(t_chunk) == (uintptr_t)ptr)
				return (chunk);
			chunk = chunk->next;
		}
		*idx += 1;
	}
	return (NULL);
}
