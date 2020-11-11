/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <roster@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 08:41:18 by roster            #+#    #+#             */
/*   Updated: 2020/09/03 08:56:48 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*
** Calloc test. official doesn't return null but a unique pointer. I choose to
** return NULL as the man said
*/

void	print(char *s)
{
	write(1, s, strlen(s));
}

int		main(void)
{
	char *addr;

	if ((addr = (char*)calloc(1, 0)) == NULL)
		print("Bonjours\n");
	if ((addr = (char*)calloc(0, 5)) == NULL)
		print("Bonjours\n");
	addr = calloc(10, 5);
	strcpy(addr, "Bonjour\n");
	print(addr);
	return (0);
}
