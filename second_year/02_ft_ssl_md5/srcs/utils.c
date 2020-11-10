/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 10:52:31 by roster            #+#    #+#             */
/*   Updated: 2020/05/08 07:49:16 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/*
** Create a malloc string of the content readed, by joining what as already
** been read before
*/

static char	*readjoin(char *dst, char *src, size_t total_readed, size_t readed)
{
	char *join;

	if (!(dst))
	{
		if (!(join = (char*)malloc(sizeof(char) * readed)))
			return (NULL);
		join = ft_memcpy(join, src, readed);
		return (join);
	}
	else
	{
		if (!(join = (char*)malloc(sizeof(char) * total_readed)))
			return (NULL);
		join = ft_memcpy(join, dst, total_readed - readed);
		join = ft_memncpy(join, src, total_readed - readed, readed);
		ft_strdel(&dst);
	}
	return (join);
}

/*
** Read the entire file if path exists, otherwise stdin (fd => 0), and
** return a malloc string of the content or NULL. In case where the file is
** empty it creates a string "/0" and return it.
** fcntl and unistdh for respectively open() and close()
*/

t_data		read_file(char *path, int status)
{
	char	buf[READ_SIZE];
	int		fd;
	int		ret;
	t_data	data;

	data.msg = status == STRING ? path : NULL;
	data.msg_len = status == STRING ? ft_strlen(path) : 0;
	fd = 0;
	if (path && status != STRING)
		fd = open(path, O_RDONLY);
	if (fd >= 0 && status != STRING)
	{
		data.msg = ft_strnew(1);
		while ((ret = read(fd, buf, READ_SIZE)) > 0)
		{
			data.msg_len += ret;
			data.msg = readjoin(data.msg, buf, data.msg_len, ret);
		}
		close(fd);
	}
	return (data);
}
