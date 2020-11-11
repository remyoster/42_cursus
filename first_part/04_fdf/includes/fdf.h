/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:55:04 by roster            #+#    #+#             */
/*   Updated: 2019/02/12 18:50:12 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# define ABS(Value) Value > 0 ? Value : -Value
# define WIDTH 2560
# define HEIGHT 1400
# define CONST 15
# define ZOOM 1

typedef struct	s_pix
{
	int			z;
	int			h;
	int			tmp;
}				t_pix;

typedef struct	s_pos
{
	size_t		x;
	size_t		y;
	int			z;

}				t_pos;

typedef struct	s_rgb
{
	int			a;
	int			r;
	int			g;
	int			b;
	int			bol;
}				t_rgb;

typedef struct	s_evt
{
	int			dx;
	int			dy;
	int			dx_st;
	int			dy_st;
	int			gap_x;
	int			gap_y;
}				t_evt;

typedef struct	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_str;
	int			bpp;
	int			s_l;
	int			endian;
	int			mark_x;
	int			mark_y;
	t_pos		pos;
	t_evt		evt;
	t_rgb		rgb;
	t_pix		**pix;
	int			proj;
	double		cst_proj;
	int			dir_h;
	int			dir_v;
	size_t		degrade;
}				t_win;

typedef struct	s_crd
{
	int			x0;
	int			y0;
	t_rgb		rgb_pt0;
	int			x1;
	int			y1;
	t_rgb		rgb_pt1;
	int			e;
	int			m;
	int			dx;
	int			dy;
}				t_crd;

t_pix			**ft_create_map(int fd, t_pos pos);
void			ft_usage(int bol);
t_pos			ft_check_file(int fd);
void			ft_fill_window(t_win *win);
void			ft_fill_window_part2(t_win *win);
void			ft_fill_window_iso(t_win *win);
void			ft_fill_window_para(t_win *win);
void			ft_bresenham(char *img_str, t_crd crd);
int				ft_deal_key(int key, t_win *win);
void			ft_fill_pixel(char *img_str, int x, int y, t_rgb rgb);
void			ft_legends(t_win win);
void			ft_colors(t_rgb *rgb);
int				ft_atoi_base_fdf(char *str);
void			ft_hexa_to_rgb(int res, t_rgb *rgb);
void			ft_rgb_to_white(t_rgb *rgb);
void			ft_int_to_char(t_rgb *rgb);
void			ft_cmp_rgb(t_crd *crd, int count);
void			ft_mountain(t_win win);
void			ft_first_pt(t_win *win);
int				ft_rgb_to_int(int r, int g, int b);
void			ft_degrade(t_win win, size_t degrade);
void			ft_rainbow(t_win win);
void			ft_reverse_rainbow(t_win win);
int				ft_srch_extrem_val_fdf(t_pix **tab,
				size_t i, size_t j, int mod);
void			ft_arrow(int key, t_win *win);
void			ft_high(int key, t_win *win);
void			ft_zoom(int key, t_win *win);
void			ft_coloring(int key, t_win *win);
void			ft_recenter(t_win *win);
void			ft_change_proj(t_win *win);
void			ft_gap(t_win *win);

#endif
