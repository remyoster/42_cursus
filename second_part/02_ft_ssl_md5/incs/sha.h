/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 11:14:22 by roster            #+#    #+#             */
/*   Updated: 2020/04/23 11:19:18 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA_H
# define SHA_H

/*
** Respectively for uint_t and size_t
*/

# include <stdint.h>
# include <string.h>

/*
** #####################################
**				SHA256
** #####################################
*/

/*
** Eight buffers structure of 32 bits-word
*/

typedef struct	s_buf_sha256
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	e;
	uint32_t	f;
	uint32_t	g;
	uint32_t	h;
}				t_buf_sha256;

/*
** Constants
*/

uint32_t		sha256_cst_k(size_t idx);

/*
** Round functions
*/

uint32_t		sha256_epsi0(uint32_t x);
uint32_t		sha256_epsi1(uint32_t x);
uint32_t		sha256_om0(uint32_t x);
uint32_t		sha256_om1(uint32_t x);
uint32_t		sha256_ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t		sha256_maj(uint32_t x, uint32_t y, uint32_t z);

/*
** Buf operations functions
*/

t_buf_sha256	init_sha256_ctx(void);
t_buf_sha256	sha256_add_buf(t_buf_sha256 st, t_buf_sha256 nd);
t_buf_sha256	sha256_copy_buf(t_buf_sha256 dst, t_buf_sha256 src);
void			sha256_rotate_buf(t_buf_sha256 *buf, uint32_t t1,
				uint32_t t2);

/*
** #####################################
** 				SHA384-512
** #####################################
*/

/*
** Eight buffers structure of 64 bits-word
*/

typedef struct	s_buf_sha512
{
	uint64_t	a;
	uint64_t	b;
	uint64_t	c;
	uint64_t	d;
	uint64_t	e;
	uint64_t	f;
	uint64_t	g;
	uint64_t	h;
}				t_buf_sha512;

/*
** Round functions
*/

uint64_t		sha512_epsi0(uint64_t x);
uint64_t		sha512_epsi1(uint64_t x);
uint64_t		sha512_om0(uint64_t x);
uint64_t		sha512_om1(uint64_t x);
uint64_t		sha512_ch(uint64_t x, uint64_t y, uint64_t z);
uint64_t		sha512_maj(uint64_t x, uint64_t y, uint64_t z);

/*
** Constants
*/

uint64_t		sha512_cst_k(size_t idx);

/*
** Buf operations functions
*/

t_buf_sha512	init_sha512_ctx(int mod);
t_buf_sha512	sha512_add_buf(t_buf_sha512 st, t_buf_sha512 nd);
t_buf_sha512	sha512_copy_buf(t_buf_sha512 dst, t_buf_sha512 src);
void			sha512_rotate_buf(t_buf_sha512 *buf, uint64_t t1,
				uint64_t t2);

#endif
