/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 09:55:28 by roster            #+#    #+#             */
/*   Updated: 2020/05/08 07:50:28 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdlib.h>

/*
** del function is applied on each t_list node to free it's content
** If the hash is not an error it frees the string value and if it is from stdin
** it frees the src string too. Then it frees the node himself
*/

void	del(void *content)
{
	t_hash *hash;

	hash = (t_hash*)content;
	if (hash->status != ERR)
		ft_strdel((char**)(&(hash->value)));
	if (hash->status == STDIN)
		ft_strdel(&(hash->src));
	free(content);
}

/*
** Create a empty malloc string to get the flags, calls the parser. If there is
** an error, the parser handle it and return false, then it frees the flags and
** stop. Else it proceed hashes, then print them and free the list created.
*/

int		main(int argc, char **argv)
{
	char	*flags;
	t_list	*hash_lst;
	size_t	idx;

	if (argc > 1)
	{
		idx = 2;
		flags = ft_strnew(ft_strlen(A_FLAGS));
		if (!(parser(argv, &flags, &idx)))
		{
			ft_strdel(&flags);
			return (0);
		}
		hash_lst = toggle_hashes(argc, argv, idx, flags);
		print_hash(&hash_lst, argv[1], flags);
		ft_strdel(&flags);
		ft_lstdel(&hash_lst, del);
	}
	else
		usage();
	return (0);
}
