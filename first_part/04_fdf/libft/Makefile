# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roster <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 11:28:35 by roster            #+#    #+#              #
#    Updated: 2019/02/06 17:01:05 by roster           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_memalloc.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memdel.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar.c \
	   ft_putchar_fd.c \
	   ft_putendl.c \
	   ft_putendl_fd.c \
	   ft_putnbr.c \
	   ft_putnbr_fd.c \
	   ft_putstr.c \
	   ft_putstr_fd.c \
	   ft_strcat.c \
	   ft_strchr.c \
	   ft_strclr.c \
	   ft_strcmp.c \
	   ft_strcpy.c \
	   ft_strdel.c \
	   ft_strdup.c \
	   ft_strequ.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlen.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strncat.c \
	   ft_strncmp.c \
	   ft_strncpy.c \
	   ft_strnequ.c \
	   ft_strnew.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strsplit.c \
	   ft_strstr.c \
	   ft_strsub.c \
	   ft_strtrim.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_strsplit_list.c \
	   ft_print_list.c \
	   ft_swap.c \
	   ft_lstcount.c \
	   ft_sqrt.c \
	   ft_power.c \
	   ft_sort_tab.c \
	   get_next_line.c \
	   ft_strjoin_free.c \
	   ft_lstreverse.c \
	   ft_tabdel.c \
	   ft_tabdel_char.c \
	   ft_strchr_count.c \
	   ft_strnchr_count.c \
	   ft_srch_extrem_val.c


INCLUDE = libft.h 

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRCS) -I $(INCLUDE) | echo "\x1b[35m ✓ Creation of .o\x1b[0m"
	@ar rc $(NAME) $(OBJS) | echo "\x1b[32m ✓ Creation of $(NAME)\x1b[0m"
	@ranlib $(NAME) | echo "\x1b[33m 〢 Indexing $(NAME)\x1b[0m"

clean:
	@/bin/rm -f $(OBJS) | echo "\x1b[31m ✗ Deleting .o\x1b[0m"

fclean: clean
	@/bin/rm -f $(NAME) | echo "\x1b[31m ✗ Deleting $(NAME)\x1b[0m"

re: 
	@Make fclean 
	@Make all
