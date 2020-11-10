/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 09:36:19 by roster            #+#    #+#             */
/*   Updated: 2020/04/24 13:47:26 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** Print a understandeable hexadecimal string of the hash string
*/

static void	print_hex(uint8_t *str, size_t hash_size)
{
	size_t idx;

	idx = 0;
	while (idx < hash_size)
	{
		ft_printf("%02x", (unsigned char)str[idx]);
		idx++;
	}
}

/*
** Deal stind case
*/

static void	print_stdin(t_list *hash_node, char *flags)
{
	t_hash *hash;

	hash = (t_hash*)(hash_node->content);
	if (ft_strchr(flags, 'q'))
	{
		if (ft_strchr(flags, 'p'))
			ft_putstr(hash->src);
		print_hex(hash->value, hash->size);
	}
	else if (ft_strchr(flags, 'p'))
	{
		ft_putstr(hash->src);
		print_hex(hash->value, hash->size);
	}
	else if (ft_strchr(flags, 'r'))
	{
		print_hex(hash->value, hash->size);
		ft_putstr(" *stin");
	}
	else
		print_hex(hash->value, hash->size);
	ft_putchar('\n');
}

/*
** Deal with file or string case.
** To test differences on file between openssl and ft_ssl i don't put spaces
** when it's a file
*/

static void	print_file_or_str(t_list *h_node, char *algo, char *flags, int mod)
{
	t_hash *hash;

	hash = (t_hash*)(h_node->content);
	if (ft_strchr(flags, 'q'))
		print_hex(hash->value, hash->size);
	else if (ft_strchr(flags, 'r'))
	{
		print_hex(hash->value, hash->size);
		if (mod == FILE)
			ft_printf(" %s", hash->src);
		else
			ft_printf(" \"%s\"", hash->src);
	}
	else
	{
		if (mod == FILE)
			ft_printf("%s(%s)= ", ft_str_toupper(algo), hash->src);
		else
			ft_printf("%s (\"%s\") = ", ft_str_toupper(algo), hash->src);
		print_hex(hash->value, hash->size);
	}
	ft_putchar('\n');
}

/*
** Print the hash list depending on hash status
*/

void		print_hash(t_list **hash, char *algo, char *flags)
{
	t_list	*tmp;

	tmp = *hash;
	while (tmp)
	{
		if (((t_hash *)(tmp->content))->status == STDIN)
			print_stdin(tmp, flags);
		else if (((t_hash *)(tmp->content))->status == FILE)
			print_file_or_str(tmp, algo, flags, FILE);
		else if (((t_hash *)(tmp->content))->status == STRING)
			print_file_or_str(tmp, algo, flags, STRING);
		else
			print_invalid_path(algo, ((t_hash *)(tmp->content))->src);
		tmp = tmp->next;
	}
}
