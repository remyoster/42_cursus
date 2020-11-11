/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_buf_ope.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 08:05:53 by roster            #+#    #+#             */
/*   Updated: 2020/04/24 08:06:21 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha.h"

/*
** Init sha256 buffers with magical numbers
*/

t_buf_sha256	init_sha256_ctx(void)
{
	t_buf_sha256 buf;

	buf.a = 0x6a09e667;
	buf.b = 0xbb67ae85;
	buf.c = 0x3c6ef372;
	buf.d = 0xa54ff53a;
	buf.e = 0x510e527f;
	buf.f = 0x9b05688c;
	buf.g = 0x1f83d9ab;
	buf.h = 0x5be0cd19;
	return (buf);
}

/*
** Add values of two buffers struct and return t_buf_sha256 total
*/

t_buf_sha256	sha256_add_buf(t_buf_sha256 st, t_buf_sha256 nd)
{
	t_buf_sha256 total;

	total.a = st.a + nd.a;
	total.b = st.b + nd.b;
	total.c = st.c + nd.c;
	total.d = st.d + nd.d;
	total.e = st.e + nd.e;
	total.f = st.f + nd.f;
	total.g = st.g + nd.g;
	total.h = st.h + nd.h;
	return (total);
}

/*
** Rotate buffers from a -> d -> c -> b -> a
*/

void			sha256_rotate_buf(t_buf_sha256 *buf, uint32_t t1, uint32_t t2)
{
	buf->h = buf->g;
	buf->g = buf->f;
	buf->f = buf->e;
	buf->e = buf->d + t1;
	buf->d = buf->c;
	buf->c = buf->b;
	buf->b = buf->a;
	buf->a = t1 + t2;
}

/*
** Copy values of src in dest
*/

t_buf_sha256	sha256_copy_buf(t_buf_sha256 dst, t_buf_sha256 src)
{
	dst.a = src.a;
	dst.b = src.b;
	dst.c = src.c;
	dst.d = src.d;
	dst.e = src.e;
	dst.f = src.f;
	dst.g = src.g;
	dst.h = src.h;
	return (dst);
}
