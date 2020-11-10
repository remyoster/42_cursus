/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_buf_ope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 11:21:52 by roster            #+#    #+#             */
/*   Updated: 2020/04/23 11:20:41 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

/*
** Init md5 buffers with magical numbers
*/

t_buf_md5	init_md5_ctx(void)
{
	t_buf_md5 buf;

	buf.a = 0x67452301;
	buf.b = 0xefcdab89;
	buf.c = 0x98badcfe;
	buf.d = 0x10325476;
	return (buf);
}

/*
** Add values of two buffers struct and return t_buf_md5 total
*/

t_buf_md5	md5_add_buf(t_buf_md5 st, t_buf_md5 nd)
{
	t_buf_md5 total;

	total.a = st.a + nd.a;
	total.b = st.b + nd.b;
	total.c = st.c + nd.c;
	total.d = st.d + nd.d;
	return (total);
}

/*
** Rotate buffers from a -> d -> c -> b -> a
*/

void		md5_rotate_buf(t_buf_md5 *buf)
{
	uint32_t tmp;

	tmp = buf->d;
	buf->d = buf->c;
	buf->c = buf->b;
	buf->b = buf->a;
	buf->a = tmp;
}

/*
** Copy values of src in dst and return dst
*/

t_buf_md5	md5_copy_buf(t_buf_md5 dst, t_buf_md5 src)
{
	dst.a = src.a;
	dst.b = src.b;
	dst.c = src.c;
	dst.d = src.d;
	return (dst);
}
