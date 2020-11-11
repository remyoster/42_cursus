/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 11:17:23 by roster            #+#    #+#             */
/*   Updated: 2020/04/24 13:37:23 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"
#include "libft.h"
#include <stdlib.h>

/*
** Each step reference is based on Rivest's rfc1321 documentation :
** https://tools.ietf.org/html/rfc1321
*/

/*
** Step 1 and 2
** It calculates the space needed for the padding + length appending (1 byte
** and 8 bytes = 9) then it padds + appends.
** The length appending must be in a 64 bits reprensation and
** must be a multiple of 8
*/

static size_t		prepare_message(char *msg, uint8_t **digest, size_t len)
{
	size_t	idx;
	size_t	o_len;

	o_len = len;
	while ((len + 9) % 64)
		len++;
	if (!(*digest = (uint8_t *)ft_memalloc((len + 9) * sizeof(uint8_t))))
		return (0);
	*digest = ft_memcpy(*digest, msg, o_len);
	(*digest)[o_len] = 0x80;
	len += 1;
	idx = 0;
	o_len *= 8;
	while (idx < 8)
	{
		(*digest)[len + idx] = (uint8_t)((o_len >> (8 * idx)) & 0xff);
		idx++;
	}
	return (len + idx);
}

/*
** Corresponding of the 64 operations divided in 16 rounds.
*/

static t_buf_md5	md5_hash(t_buf_md5 buf, uint32_t x[16])
{
	size_t		idx;
	uint32_t	(*fct[4])(uint32_t, uint32_t, uint32_t);

	fct[0] = &md5_f;
	fct[1] = &md5_g;
	fct[2] = &md5_h;
	fct[3] = &md5_i;
	idx = 0;
	while (idx < 64)
	{
		buf.a += fct[idx / 16](buf.b, buf.c, buf.d)
			+ x[md5_cst_k(idx)] + md5_cst_t(idx);
		buf.a = rotate_left(buf.a, md5_cst_s(idx));
		buf.a += buf.b;
		md5_rotate_buf(&buf);
		idx++;
	}
	return (buf);
}

/*
** Step 3 and 4 except that the context in initialize in md5 main function
** and passed here
*/

static t_buf_md5	process_algo(uint8_t *digest, size_t msg_len, t_buf_md5 ctx)
{
	size_t		i;
	size_t		j;
	uint32_t	x[16];
	t_buf_md5	buf;

	buf = init_md5_ctx();
	i = 0;
	while (i < msg_len / 64)
	{
		j = 0;
		while (j < 16)
		{
			x[j] = ((uint32_t*)digest)[(i * 16) + j];
			j++;
		}
		buf = md5_hash(buf, x);
		ctx = md5_add_buf(buf, ctx);
		buf = md5_copy_buf(buf, ctx);
		i++;
	}
	return (ctx);
}

/*
** Encode four 32-bits words into a 128 bits message (or char[16])
** Based on Rivest's rfc1321 documentation :
** https://tools.ietf.org/html/rfc1321
*/

static void			encode(t_buf_md5 ctx, uint8_t **digest)
{
	size_t		i;
	size_t		j;
	uint32_t	input[4];

	input[0] = ctx.a;
	input[1] = ctx.b;
	input[2] = ctx.c;
	input[3] = ctx.d;
	i = 0;
	j = 0;
	while (i < 4)
	{
		(*digest)[j] = (uint8_t)(input[i] & 0xff);
		(*digest)[j + 1] = (uint8_t)((input[i] >> 8) & 0xff);
		(*digest)[j + 2] = (uint8_t)((input[i] >> 16) & 0xff);
		(*digest)[j + 3] = (uint8_t)((input[i] >> 24) & 0xff);
		i++;
		j += 4;
	}
}

/*
** Return 128 bits encoded message that must be read in hexa.
** msg is the message to digest and msg_len is it's length
** First it inits a 4 words buffers, then prepare the message then digest it
** then encode it in a malloc string.
** Padding, parsing and encoding follows little-endian
** (the least significant byte first)
*/

uint8_t				*md5(char *msg, size_t msg_len)
{
	uint8_t		*digest;
	t_buf_md5	ctx;

	ctx = init_md5_ctx();
	msg_len = prepare_message(msg, &digest, msg_len);
	ctx = process_algo(digest, msg_len, ctx);
	ft_strdel((char**)&digest);
	if (!(digest = (uint8_t *)malloc(sizeof(uint8_t) * 16)))
		return (NULL);
	encode(ctx, &digest);
	return (digest);
}
