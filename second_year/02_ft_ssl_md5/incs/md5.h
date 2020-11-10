/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 08:37:43 by roster            #+#    #+#             */
/*   Updated: 2020/04/23 11:19:53 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

/*
** Respectively for uint_t and size_t
*/

# include <stdint.h>
# include <string.h>

/*
** Four buffers structure of 32 bits-word
*/

typedef struct		s_buf_md5
{
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
}					t_buf_md5;

/*
** Constants
*/

uint32_t			md5_cst_t(size_t idx);
uint32_t			md5_cst_k(size_t idx);
uint32_t			md5_cst_s(size_t idx);

/*
** Round functions
*/

uint32_t			rotate_left(uint32_t x, uint32_t s);
uint32_t			md5_f(uint32_t x, uint32_t y, uint32_t z);
uint32_t			md5_g(uint32_t x, uint32_t y, uint32_t z);
uint32_t			md5_h(uint32_t x, uint32_t y, uint32_t z);
uint32_t			md5_i(uint32_t x, uint32_t y, uint32_t z);

/*
** Buf operations functions
*/

void				md5_rotate_buf(t_buf_md5 *buf);
t_buf_md5			md5_copy_buf(t_buf_md5 dst, t_buf_md5 src);
t_buf_md5			init_md5_ctx(void);
t_buf_md5			md5_add_buf(t_buf_md5 st, t_buf_md5 nd);

#endif
