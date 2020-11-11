/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 11:27:49 by roster            #+#    #+#             */
/*   Updated: 2020/04/24 09:04:17 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha.h"
#include "libft.h"
#include <stdlib.h>

/*
** Calculate the missing length to be a multiple of 512, memalloc a string of
** the good final length, copy the original mess in it, add 1 bit, and append
** the length of the original message at the end. The length appended must be
** a multiple of 8.
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
		(*digest)[len + idx] = (uint8_t)((o_len >> (8 * (7 - idx))) & 0xff);
		idx++;
	}
	return (len + idx);
}

/*
** Corresponding of the 64 operations
*/

static t_buf_sha256	sha256_hash(t_buf_sha256 buf, uint32_t x[16])
{
	size_t		idx;
	uint32_t	t1;
	uint32_t	t2;
	uint32_t	w[64];

	idx = 0;
	while (idx < 64)
	{
		if (idx < 16)
			w[idx] = x[idx];
		else
			w[idx] = sha256_om1(w[idx - 2]) + w[idx - 7]
				+ sha256_om0(w[idx - 15]) + w[idx - 16];
		t1 = buf.h + sha256_epsi1(buf.e) + sha256_ch(buf.e, buf.f, buf.g)
			+ sha256_cst_k(idx) + w[idx];
		t2 = sha256_epsi0(buf.a) + sha256_maj(buf.a, buf.b, buf.c);
		sha256_rotate_buf(&buf, t1, t2);
		idx++;
	}
	return (buf);
}

/*
** Parse the message into block of 16 words of 32bits and proceed to hash and
** buffers additions. Docs 6.2
*/

static t_buf_sha256	process_algo(uint8_t *digest, size_t msg_len,
	t_buf_sha256 ctx)
{
	size_t			i;
	size_t			j;
	uint32_t		x[16];
	t_buf_sha256	buf;

	buf = init_sha256_ctx();
	i = 0;
	while (i < msg_len / 64)
	{
		j = 0;
		while (j < 16)
		{
			x[j] = ((uint32_t)digest[0] << 24) | ((uint32_t)digest[1] << 16)
			| ((uint32_t)digest[2] << 8) | ((uint32_t)digest[3]);
			digest += 4;
			j++;
		}
		buf = sha256_hash(buf, x);
		ctx = sha256_add_buf(buf, ctx);
		buf = sha256_copy_buf(buf, ctx);
		i++;
	}
	return (ctx);
}

/*
** Encode the final message into digest (32 bytes = 256 bits)
*/

static void			encode(t_buf_sha256 ctx, uint8_t **digest)
{
	size_t		i;
	size_t		j;
	uint32_t	input[8];

	input[0] = ctx.a;
	input[1] = ctx.b;
	input[2] = ctx.c;
	input[3] = ctx.d;
	input[4] = ctx.e;
	input[5] = ctx.f;
	input[6] = ctx.g;
	input[7] = ctx.h;
	i = 0;
	j = 0;
	while (i < 8)
	{
		(*digest)[j] = (uint8_t)((input[i] >> 24) & 0xff);
		(*digest)[j + 1] = (uint8_t)((input[i] >> 16) & 0xff);
		(*digest)[j + 2] = (uint8_t)((input[i] >> 8) & 0xff);
		(*digest)[j + 3] = (uint8_t)(input[i] & 0xff);
		i++;
		j += 4;
	}
}

/*
** Return 256 bits encoded message that must be read in hexa.
** msg is the message to digest and msg_len is it's length
** First it inits a 8 words buffers, then prepare the message then digest it
** then encode it in a malloc string.
** The padding and encoding follows big-endian (the most significant byte first)
*/

uint8_t				*sha256(char *msg, size_t msg_len)
{
	uint8_t			*digest;
	t_buf_sha256	ctx;

	ctx = init_sha256_ctx();
	msg_len = prepare_message(msg, &digest, msg_len);
	ctx = process_algo(digest, msg_len, ctx);
	ft_strdel((char**)&digest);
	if (!(digest = (uint8_t *)malloc(sizeof(uint8_t) * 32)))
		return (NULL);
	encode(ctx, &digest);
	return (digest);
}
