/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:06:21 by roster            #+#    #+#             */
/*   Updated: 2019/01/11 12:30:48 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define TETRI_AREA 4
# include "libft/libft.h"

typedef struct	s_pos
{
	int			x;
	int			y;
	int			i;
	int			j;
}				t_pos;

typedef struct	s_mark
{
	int			nb_tetri;
	int			map_size;
	int			x;
	int			tab[26][3];
	char		**map;
}				t_mark;

int				ft_check_file(int fd, t_pos pos);
void			ft_usage(int bol);
char			**ft_create_map(int map_size, int nb_tetri);
char			**ft_tetri_to_alpha(char **tetri, int fd);
char			**ft_resolve(char **tetri, t_pos *pos, t_mark *mark);
int				ft_check_and_join(char **line, char **tetri, int bol);
void			ft_check_content(char *tetri, t_pos *pos);
char			*ft_trim_all(char *str);
int				ft_check_tetri(char *s);
int				ft_map_area(int map_size, int nb_tetri);
void			ft_place_mark(char **tetri, t_pos *pos, t_mark *mark);
void			ft_backtrack(char **tetri, t_pos *pos, t_mark *mark);
char			**ft_reset_map(char **tetri, t_pos *pos, t_mark *mark);

#endif
