/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 08:11:41 by roster            #+#    #+#             */
/*   Updated: 2020/05/08 07:47:10 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		init_hash(t_hash *hash, char *algo, t_data data)
{
	char *lower;

	lower = ft_str_tolower(algo);
	if (ft_strcmp("md5", lower) == 0)
	{
		hash->value = md5(data.msg, data.msg_len);
		hash->size = 16;
	}
	else if (ft_strcmp("sha256", lower) == 0)
	{
		hash->value = sha256(data.msg, data.msg_len);
		hash->size = 32;
	}
	else if (ft_strcmp("sha384", lower) == 0)
	{
		hash->value = sha512(data.msg, data.msg_len, 384);
		hash->size = 48;
	}
	else if (ft_strcmp("sha512", lower) == 0)
	{
		hash->value = sha512(data.msg, data.msg_len, 512);
		hash->size = 64;
	}
}

static t_hash	proceed_hash(char *algo, char *src, int status)
{
	t_hash hash;
	t_data data;

	data = read_file(src, status);
	hash.src = src;
	if (status == STDIN)
		hash.src = data.msg;
	hash.status = status;
	if (data.msg)
	{
		init_hash(&hash, algo, data);
		if (status == FILE)
			ft_strdel(&(data.msg));
	}
	else
		hash.status = ERR;
	return (hash);
}

t_list			*toggle_hashes(int ac, char **av, size_t idx, char *flags)
{
	t_list *lst;
	t_hash hash;

	lst = NULL;
	if (ft_strchr(flags, 'p') || ac == 2 || ac == (int)ft_strlen(flags) + 2)
	{
		hash = proceed_hash(av[1], NULL, STDIN);
		ft_lstpush(&lst, ft_lstnew(&hash, sizeof(t_hash)));
	}
	if (ft_strchr(flags, 's'))
	{
		hash = proceed_hash(av[1], av[idx], STRING);
		ft_lstpush(&lst, ft_lstnew(&hash, sizeof(t_hash)));
		idx++;
	}
	while (av[idx])
	{
		hash = proceed_hash(av[1], av[idx], FILE);
		ft_lstpush(&lst, ft_lstnew(&hash, sizeof(t_hash)));
		idx++;
	}
	return (lst);
}
