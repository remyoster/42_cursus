/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_basic_fcts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 09:06:32 by roster            #+#    #+#             */
/*   Updated: 2020/04/17 09:45:00 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

/*
** Each constant reference is based on Rivest's rfc1321 documentation :
** https://tools.ietf.org/html/rfc1321
*/

/*
** Refers to the rotate function which is applied at each round
*/

uint32_t	rotate_left(uint32_t x, uint32_t s)
{
	return (((x) << (s)) | ((x) >> (32 - (s))));
}

/*
** Refers to F fct
*/

uint32_t	md5_f(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x) & (y)) | ((~x) & (z)));
}

/*
** Refers to G fct
*/

uint32_t	md5_g(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x) & (z)) | ((y) & (~z)));
}

/*
** Refers to H fct
*/

uint32_t	md5_h(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x) ^ (y) ^ (z));
}

/*
** Refers to I fct
*/

uint32_t	md5_i(uint32_t x, uint32_t y, uint32_t z)
{
	return ((y) ^ ((x) | (~z)));
}
