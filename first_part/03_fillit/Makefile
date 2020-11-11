# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roster <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/09 12:29:06 by roster            #+#    #+#              #
#    Updated: 2019/01/14 14:13:08 by lojesu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

# Colors
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m

NAME = fillit

FLAGS = -Wall -Wextra -Werror

INCLUDES = fillit.h 

SRCS = ft_check_file.c \
	   ft_trim_all.c \
	   ft_tetri_to_alpha.c \
	   ft_check_and_join.c \
	   ft_usage.c \
	   main.c \
	   ft_create_map.c \
	   ft_resolve.c \
	   ft_manage_map.c

OBJS = $(SRCS:.c=.o)

LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc -c $(FLAGS) $(SRCS) -I $(INCLUDES)
	@echo "$(BLUE) ✓ Creation of .o"
	@gcc $(OBJS) $(LIB) -o $(NAME)
	@echo "$(GREEN) ✓ Creation of $(NAME)"

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJS)
	@echo "$(RED) ✗ Deletion of .o"

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)
	@echo "$(RED) ✗ Deletion of $(NAME)"

re:
	@Make fclean
	@Make all
