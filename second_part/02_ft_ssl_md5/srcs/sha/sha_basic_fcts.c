/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_basic_fcts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 11:23:23 by roster            #+#    #+#             */
/*   Updated: 2020/04/23 11:23:48 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

/*
** Reference from https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf
*/

uint32_t	sha256_ch(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x) & (y)) ^ (~(x) & (z)));
}

uint32_t	sha256_maj(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)));
}

uint64_t	sha512_ch(uint64_t x, uint64_t y, uint64_t z)
{
	return (((x) & (y)) ^ (~(x) & (z)));
}

uint64_t	sha512_maj(uint64_t x, uint64_t y, uint64_t z)
{
	return (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)));
}
