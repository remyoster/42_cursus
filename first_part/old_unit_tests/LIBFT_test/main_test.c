/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:58:42 by roster            #+#    #+#             */
/*   Updated: 2018/11/18 16:38:40 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rosterlinette.h"

int		main(void)
{
	int i;
	int j;
	int (*tabmain[28])(void);

	print_begin_main();
	tabmain[0] = ft_memset_test;
	tabmain[1] = ft_bzero_test;
	tabmain[2] = ft_memcpy_test;
	tabmain[3] = ft_memccpy_test;
	tabmain[4] = ft_memmove_test;
	tabmain[5] = ft_memchr_test;
	tabmain[6] = ft_memcmp_test;
	tabmain[7] = ft_strlen_test;
	tabmain[8] = ft_strdup_test;
	tabmain[9] = ft_strcpy_test;
	tabmain[10] = ft_strncpy_test;
	tabmain[11] = ft_strcat_test;
	tabmain[12] = ft_strncat_test;
	tabmain[13] = ft_strlcat_test;
	tabmain[14] = ft_strchr_test;
	tabmain[15] = ft_strrchr_test;	
	tabmain[16] = ft_strstr_test;
	tabmain[17] = ft_strnstr_test;
	tabmain[18] = ft_strcmp_test;
	tabmain[19] = ft_strncmp_test;
	tabmain[20] = ft_atoi_test;
	tabmain[21] = ft_isalpha_test;
	tabmain[22] = ft_isdigit_test;
	tabmain[23] = ft_isalnum_test;
	tabmain[24] = ft_isascii_test;
	tabmain[25] = ft_isprint_test;
	tabmain[26] = ft_toupper_test;
	tabmain[27] = ft_tolower_test;	
	i = 0;
	j = 0;
	while (i <= 27)
	{
		if ((*tabmain[i])() != 0)
			j++;
		i++;
	}
	print_end_main(j);

//FONCTION SUPP
	int (*tabsup[24])(void);
	print_begin_add();
	tabsup[0] = ft_memalloc_test;
	tabsup[1] = ft_memdel_test;
	tabsup[2] = ft_strnew_test;
	tabsup[3] = ft_strdel_test;
	tabsup[4] = ft_strclr_test;
	tabsup[5] = ft_striter_test;
	tabsup[6] = ft_striteri_test;
	tabsup[7] = ft_strmap_test;
	tabsup[8] = ft_strmapi_test;
	tabsup[9] = ft_strequ_test;
	tabsup[10] = ft_strnequ_test;
	tabsup[11] = ft_strsub_test;
	tabsup[12] = ft_strjoin_test;
	tabsup[13] = ft_strtrim_test;
	tabsup[14] = ft_strsplit_test;
	tabsup[15] = ft_itoa_test;
	/*	tabsup[16] = ft_putchar_test;
		tabsup[17] = ft_putstr_test;
		tabsup[18] = ft_putendl_test;
		tabsup[19] = ft_putnbr_test;
		tabsup[20] = ft_putnbr_fd_test;
		tabsup[21] = ft_putstr_fd_test;
		tabsup[22] = ft_putendl_fd_test;
		tabsup[23] = ft_putnbr_fd_test;
		*/	i = 0;
	j = 0;
	while (i <= 15)
	{
		if ((*tabsup[i])() != 0)
			j++;
		i++;
	}
	print_end_main(j);
	/*	print_begin_bonus;
		int (*tabbonus[5])(void);
		tabbonus[] = ;
		tabbonus[] = ;
		tabbonus[] = ;
		tabbonus[] = ;
		tabbonus[] = ;
		i = 0;
		while (i <= 5)
		{
		(*tabbonus[i]();
		i++;
		}
		print_end_main(j);
		*/	return (0);
}
