/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:42:01 by roster            #+#    #+#             */
/*   Updated: 2018/12/21 07:39:42 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>

static int	ft_create_lst(char *tmp, int fd, t_list **lst)
{
	t_data	*elem;
	t_list	*link;

	if (!(elem = (t_data*)malloc(sizeof(t_data))))
		return (-1);
	if (!(elem->str = (char*)malloc(sizeof(char) * (ft_strlen(tmp) + 1))))
		return (-1);
	elem->str = ft_strcpy(elem->str, tmp);
	elem->val = fd;
	if (!*lst)
	{
		if (!(*lst = ft_lstnew(elem, sizeof(struct s_data))))
			return (-1);
	}
	else
	{
		if (!(link = ft_lstnew(elem, sizeof(struct s_data))))
			return (-1);
		ft_lstadd(lst, link);
	}
	free(elem);
	return (1);
}

static int	ft_check_buf(char *tmp, int fd, char **line, t_list **lst)
{
	size_t i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
		{
			*line = ft_strsub(tmp, 0, i);
			if (tmp[i + 1] != '\0')
				ft_create_lst(&tmp[i + 1], fd, lst);
			ft_strdel(&tmp);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_read_file(char *buf, int fd, char **line, t_list **lst)
{
	int		ret;
	char	*tmp;
	char	tmp_read[BUFF_SIZE + 1];

	if (ft_strncmp(buf, "", 1) != 0)
		tmp = ft_strdup(buf);
	else
		tmp = ft_strnew(1);
	ft_strdel(&buf);
	while ((ret = read(fd, tmp_read, BUFF_SIZE)) > 0)
	{
		tmp_read[ret] = '\0';
		if (!(tmp = ft_strjoin_free(tmp, tmp_read, 1)))
			return (-1);
		if (ft_strchr(tmp_read, '\n') != 0)
			return (ft_check_buf(tmp, fd, line, lst));
	}
	if (ret == 0 && ft_strncmp(tmp, "", 1) != 0)
	{
		*line = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (1);
	}
	ft_strdel(&tmp);
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*node1;
	t_list			*tmp;
	char			*buf;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (node1 != NULL)
	{
		tmp = node1;
		while (tmp)
		{
			if (((t_data*)tmp->content)->val == fd)
			{
				buf = ft_strcpy(buf, ((t_data*)tmp->content)->str);
				((t_data*)tmp->content)->val = -1;
				ft_strdel(&((t_data*)tmp->content)->str);
				if (ft_check_buf(buf, fd, line, &node1) == 1)
					return (1);
			}
			tmp = tmp->next;
		}
	}
	return (ft_read_file(buf, fd, line, &node1));
}
