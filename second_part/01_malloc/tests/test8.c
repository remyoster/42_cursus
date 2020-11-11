/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:22:06 by roster            #+#    #+#             */
/*   Updated: 2020/09/03 08:53:26 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/malloc.h"

/*
** Malloc + free + realloc + calloc + show_alloc_mem tests
*/

/*
** Malloc test max time with size. If bool free is true, it free the allocation
*/

void	test_malloc(size_t max, bool freed)
{
	size_t	idx;
	char	*test;

	idx = 0;
	while (idx < max)
	{
		if (!(test = (char*)malloc(sizeof(char) * (idx + 1))))
			return ;
		if (freed)
			free(test);
		idx++;
	}
}

/*
** Realloc test max time with size. If bool free is true, it free the allocation
*/

void	test_realloc(size_t max, bool freed)
{
	size_t	idx;
	char	*test;

	test = NULL;
	idx = 0;
	while (idx < max)
	{
		if (!(test = (char*)realloc(test, idx + 1)))
			return ;
		if (freed)
			free(test);
		idx++;
	}
}

/*
** Calloc test max time with size. If bool free is true, it free the allocation
*/

void	test_calloc(size_t max, bool freed)
{
	size_t	idx;
	char	*test;

	idx = 0;
	while (idx < max)
	{
		if (!(test = (char *)calloc(sizeof(t_chunk), 10 * idx)))
			return ;
		if (freed)
			free(test);
		idx++;
	}
}

/*
** Test malloc, realloc, free, calloc in a loop
*/

void	test_all(size_t max, bool freed)
{
	size_t	i;
	char	*test;
	int		*test2;

	i = 1;
	while (i < max)
	{
		if (!(test = (char *)malloc(sizeof(char) * i * 1428)))
			return ;
		if (!(test = (char *)realloc(test, 15)))
			return ;
		if (freed)
			free(test);
		if (!(test2 = (int *)malloc(sizeof(int) * i)))
			return ;
		if (!(test2 = (int *)realloc(test2, 1574)))
			return ;
		if (freed)
			free(test2);
		if (!(test = (char *)calloc(sizeof(t_chunk), 10 * i)))
			return ;
		if (freed)
			free(test);
		i++;
	}
}

int		main(void)
{
	test_malloc(42, false);
	test_realloc(42, false);
	test_calloc(42, false);
	test_all(42, false);
	show_alloc_mem();
}
