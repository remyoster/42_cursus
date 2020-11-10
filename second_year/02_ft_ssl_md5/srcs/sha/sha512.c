/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 07:58:28 by roster            #+#    #+#             */
/*   Updated: 2020/04/24 09:05:35 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha.h"
#include "libft.h"
#include <stdlib.h>

/*
** Calculate the missing length to be a multiple of 1024, memalloc a string of
** the good final length, copy the original mess in it, add 1 bit, and append
** the length of the original message at the end.
** The length appended must be a multiple of 8. As it is the length in bits,
** it can be store in a size_t (64 bits here), that's why be append the
** length on the 8 final bytes instead of on the 16.
** Padding is the same for sha384 and sha512.
*/

static size_t		prepare_message(char *msg, uint8_t **digest, size_t len)
{
	size_t	idx;
	size_t	o_len;

	o_len = len;
	while ((len + 17) % 128)
		len++;
	if (!(*digest = (uint8_t *)ft_memalloc((len + 17) * sizeof(uint8_t))))
		return (0);
	*digest = ft_memcpy(*digest, msg, o_len);
	(*digest)[o_len] = 0x80;
	len += 9;
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
** Corresponding of the 80 operations describe in 6.4
*/

static t_buf_sha512	sha512_hash(t_buf_sha512 buf, uint64_t x[16])
{
	size_t		idx;
	uint64_t	t1;
	uint64_t	t2;
	uint64_t	w[80];

	idx = 0;
	while (idx < 80)
	{
		if (idx < 16)
			w[idx] = x[idx];
		else
			w[idx] = sha512_om1(w[idx - 2]) + w[idx - 7]
				+ sha512_om0(w[idx - 15]) + w[idx - 16];
		t1 = buf.h + sha512_epsi1(buf.e) + sha512_ch(buf.e, buf.f, buf.g)
			+ sha512_cst_k(idx) + w[idx];
		t2 = sha512_epsi0(buf.a) + sha512_maj(buf.a, buf.b, buf.c);
		sha512_rotate_buf(&buf, t1, t2);
		idx++;
	}
	return (buf);
}

/*
** Parsing operation : divided the padded message in 16 words of 64 bits
** following the big endian convention. Then proceed hash and buffers additions
*/

static t_buf_sha512	process_algo(uint8_t *digest, size_t msg_len,
	t_buf_sha512 ctx, int mod)
{
	size_t			i;
	size_t			j;
	uint64_t		x[16];
	t_buf_sha512	buf;

	buf = init_sha512_ctx(mod);
	i = 0;
	while (i < msg_len / 128)
	{
		j = 0;
		while (j < 16)
		{
			x[j] = ((uint64_t)digest[0] << 56) | ((uint64_t)digest[1] << 48)
			| ((uint64_t)digest[2] << 40) | ((uint64_t)digest[3] << 32)
			| ((uint64_t)digest[4] << 24) | ((uint64_t)digest[5] << 16)
			| ((uint64_t)digest[6]) << 8 | ((uint64_t)digest[7]);
			digest += 8;
			j++;
		}
		buf = sha512_hash(buf, x);
		ctx = sha512_add_buf(buf, ctx);
		buf = sha512_copy_buf(buf, ctx);
		i++;
	}
	return (ctx);
}

/*
** Encode the message in a string. Len is for 512 or 384 (8 or 6)
*/

static void			encode(t_buf_sha512 ctx, uint8_t **digest, size_t len,
					size_t j)
{
	uint64_t	input[8];
	size_t		i;

	i = 0;
	input[0] = ctx.a;
	input[1] = ctx.b;
	input[2] = ctx.c;
	input[3] = ctx.d;
	input[4] = ctx.e;
	input[5] = ctx.f;
	input[6] = ctx.g;
	input[7] = ctx.h;
	while (i < len)
	{
		(*digest)[j] = (uint8_t)((input[i] >> 56) & 0xff);
		(*digest)[j + 1] = (uint8_t)((input[i] >> 48) & 0xff);
		(*digest)[j + 2] = (uint8_t)((input[i] >> 40) & 0xff);
		(*digest)[j + 3] = (uint8_t)((input[i] >> 32) & 0xff);
		(*digest)[j + 4] = (uint8_t)((input[i] >> 24) & 0xff);
		(*digest)[j + 5] = (uint8_t)((input[i] >> 16) & 0xff);
		(*digest)[j + 6] = (uint8_t)((input[i] >> 8) & 0xff);
		(*digest)[j + 7] = (uint8_t)(input[i] & 0xff);
		i++;
		j += 8;
	}
}

/*
** Return 512 or 384 bits encoded message that must be read in hexa.
** msg is the message to digest and msg_len is it's length
** First it inits a 8 words buffers, then prepare the message then digest it
** then encode it in a malloc string.
** The padding and encoding follows big-endian (the most significant byte first)
** The mod is usefull to know if we use sha512 or sha384. Init buffers are
** different, as encode length.
*/

uint8_t				*sha512(char *msg, size_t msg_len, int mod)
{
	uint8_t			*digest;
	t_buf_sha512	ctx;

	ctx = init_sha512_ctx(mod);
	msg_len = prepare_message(msg, &digest, msg_len);
	ctx = process_algo(digest, msg_len, ctx, mod);
	ft_strdel((char**)&digest);
	if (!(digest = (uint8_t *)malloc(sizeof(uint8_t) * (mod / 8))))
		return (NULL);
	encode(ctx, &digest, mod / 64, 0);
	return (digest);
}
