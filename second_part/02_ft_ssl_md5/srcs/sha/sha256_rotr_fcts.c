/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_rotr_fcts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 08:06:45 by roster            #+#    #+#             */
/*   Updated: 2020/04/24 08:06:50 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

/*
** FIPS 180-4
** https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf
*/

static uint32_t	rotr(uint32_t x, uint32_t n)
{
	return (((x) >> (n)) | ((x) << (32 - (n))));
}

uint32_t		sha256_epsi0(uint32_t x)
{
	return (rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22));
}

uint32_t		sha256_epsi1(uint32_t x)
{
	return (rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25));
}

uint32_t		sha256_om0(uint32_t x)
{
	return (rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3));
}

uint32_t		sha256_om1(uint32_t x)
{
	return (rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10));
}
