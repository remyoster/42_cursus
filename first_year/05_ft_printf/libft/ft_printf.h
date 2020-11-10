/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:42:27 by roster            #+#    #+#             */
/*   Updated: 2019/03/14 15:52:01 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>

typedef struct	s_flg
{
	size_t		i;
	size_t		acc;
	size_t		k;
	size_t		count;
	char		tab[30];
	char		buff[4096];
}				t_flg;

int				ft_parse_diouxx(const char *fmt, t_flg *flg, int mod);
int				ft_parse_csp(const char *fmt, t_flg *flg, int mod);
int				ft_parse_lh(const char *fmt, t_flg *flg, int mod);
int				ft_putstr_printf(char *s, t_flg *flg);
char			*ft_dispatcher(va_list ap, const char *fmt, t_flg *flg);
char			*ft_accuracy(va_list ap, const char *fmt, t_flg *flg);
char			*ft_number_flag(va_list ap, const char *fmt, t_flg *flg);
char			*ft_csp(va_list ap, const char *fmt, t_flg *flg);
char			*ft_diouxx(va_list ap, const char *fmt, t_flg *flg);
char			*ft_plus_flag(va_list ap, const char *fmt, t_flg *flg);
char			*ft_minus_flag(va_list ap, const char *fmt, t_flg *flg);
char			*ft_space_flag(va_list ap, const char *fmt, t_flg *flg);
char			*ft_binary_flag(va_list ap, const char *fmt, t_flg *flg);
char			*ft_bin_to_nb(va_list ap, const char *fmt, t_flg *flg);
char			*ft_lh_flags(va_list ap, const char *fmt, t_flg *flg);
char			*ft_hashtag(va_list ap, const char *fmt, t_flg *flg);
char			*ft_hash_oxx(char *tmp, t_flg *flg, const char *fmt);
char			*ft_float(va_list ap, char flag, t_flg *flg);
char			*ft_printf_error(va_list ap, t_flg *flg);
char			*ft_percent(t_flg *flg);
char			*ft_itoa_printf(long int nb, int base, size_t mod);

#endif
