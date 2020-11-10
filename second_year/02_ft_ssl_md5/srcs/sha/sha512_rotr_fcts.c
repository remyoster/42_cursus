/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_rotr_fcts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 08:14:09 by roster            #+#    #+#             */
/*   Updated: 2020/04/23 10:18:10 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

/*
** FIPS 180-4
** https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf
*/

static uint64_t	rotr(uint64_t x, uint64_t n)
{
	return (((x) >> (n)) | ((x) << (64 - (n))));
}

uint64_t		sha512_epsi0(uint64_t x)
{
	return (rotr(x, 28) ^ rotr(x, 34) ^ rotr(x, 39));
}

uint64_t		sha512_epsi1(uint64_t x)
{
	return (rotr(x, 14) ^ rotr(x, 18) ^ rotr(x, 41));
}

uint64_t		sha512_om0(uint64_t x)
{
	return (rotr(x, 1) ^ rotr(x, 8) ^ (x >> 7));
}

uint64_t		sha512_om1(uint64_t x)
{
	return (rotr(x, 19) ^ rotr(x, 61) ^ (x >> 6));
}
