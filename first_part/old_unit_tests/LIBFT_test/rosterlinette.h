/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rosterlinette.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roster <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:21:23 by roster            #+#    #+#             */
/*   Updated: 2018/12/09 15:54:14 by roster           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROSTERLINETTE_H
# define ROSTERLINETTE_H

# include "../../libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

//COLOR AND MESSAGE
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"
# define WRONG  printf(RED "WRONG\n"RESET); 
# define TEST1 printf("Test1: ");
# define TEST2 printf("Test2: ");
# define TEST3 printf("Test3: ");
# define TEST4 printf("Test4: ");
# define TEST5 printf("Test5: ");
# define OK printf(GREEN"OK "RESET);

void	print_begin(char *name);
void	print_begin_main(void);
void	print_begin_add(void);
void	print_begin_bonus(void);
void	print_wrong_char(char *res, char const *exp, int test_nb);
void	print_wrong_char2(char *res, char *exp, int test_nb);
void	print_wrong_int(int res, int exp, int test_nb);
void	print_wrong_size_t(size_t res, size_t exp, int test_nb);
void	print_wrong_memory(void	*mem, int test_nb);
void	print_ok(int test_nb);
void	print_end(int bol);
void	print_end_main(int bol);

//PROTO MAIN
int		ft_memset_test(void);
int		ft_bzero_test(void);
int		ft_memcpy_test(void);
int		ft_memccpy_test(void);
int		ft_memmove_test(void);
int		ft_memchr_test(void);
int		ft_memcmp_test(void);
int		ft_strlen_test(void);
int		ft_atoi_test(void);
int		ft_strdup_test(void);
int		ft_strcpy_test(void);
int		ft_strncpy_test(void);
int		ft_strcat_test(void);
int		ft_strncat_test(void);
int		ft_strlcat_test(void);
int		ft_strchr_test(void);
int		ft_strrchr_test(void);
int		ft_strstr_test(void);
int		ft_strnstr_test(void);
int		ft_strcmp_test(void);
int		ft_strncmp_test(void);
int		ft_isalpha_test(void);
int		ft_isdigit_test(void);
int		ft_isalnum_test(void);
int		ft_isascii_test(void);
int		ft_isprint_test(void);
int		ft_toupper_test(void);
int		ft_tolower_test(void);

//PROTO SUP
int		ft_memalloc_test(void);
int		ft_memdel_test(void);
int		ft_strnew_test(void);
int		ft_strdel_test(void);
int		ft_strclr_test(void);
int		ft_striter_test(void);
int		ft_striteri_test(void);
int		ft_strmap_test(void);
int		ft_strmapi_test(void);
int		ft_strequ_test(void);
int		ft_strnequ_test(void);
int		ft_strsub_test(void);
int		ft_strjoin_test(void);
int		ft_strtrim_test(void);
int		ft_strsplit_test(void);
int		ft_itoa_test(void);
int		ft_putchar_test(void);
int		ft_putstr_test(void);
int		ft_putendl_test(void);
int		ft_putnbr_test(void);
int		ft_putchar_fd_test(void);
int		ft_putstr_fd_test(void);
int		ft_putendl_fd_test(void);
int		ft_putnbr_fd_test(void);

//PROTO BONUS

#endif
