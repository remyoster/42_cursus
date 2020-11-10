/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_buf_ope.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 10:59:29 by roster            #+#    #+#             */
/*   Updated: 2020/04/24 08:07:11 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha.h"

/*
** Init sha512 buffers with magical numbers (first sixty-four bits of the
** fractional parts of the square roots of the (512) eight
** - (384)ninth through sixteenth - prime numbers.)
*/

t_buf_sha512	init_sha512_ctx(int mod)
{
	t_buf_sha512 buf;

	if (mod == 512)
	{
		buf.a = 0x6a09e667f3bcc908;
		buf.b = 0xbb67ae8584caa73b;
		buf.c = 0x3c6ef372fe94f82b;
		buf.d = 0xa54ff53a5f1d36f1;
		buf.e = 0x510e527fade682d1;
		buf.f = 0x9b05688c2b3e6c1f;
		buf.g = 0x1f83d9abfb41bd6b;
		buf.h = 0x5be0cd19137e2179;
	}
	else
	{
		buf.a = 0xcbbb9d5dc1059ed8;
		buf.b = 0x629a292a367cd507;
		buf.c = 0x9159015a3070dd17;
		buf.d = 0x152fecd8f70e5939;
		buf.e = 0x67332667ffc00b31;
		buf.f = 0x8eb44a8768581511;
		buf.g = 0xdb0c2e0d64f98fa7;
		buf.h = 0x47b5481dbefa4fa4;
	}
	return (buf);
}

/*
** Add values of two sha512 buffers struct and return t_buf_sha512 total
*/

t_buf_sha512	sha512_add_buf(t_buf_sha512 st, t_buf_sha512 nd)
{
	t_buf_sha512 total;

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
** Rotate buffers as describe in 6.2.2
** https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf
*/

void			sha512_rotate_buf(t_buf_sha512 *buf, uint64_t t1, uint64_t t2)
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

t_buf_sha512	sha512_copy_buf(t_buf_sha512 dst, t_buf_sha512 src)
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
