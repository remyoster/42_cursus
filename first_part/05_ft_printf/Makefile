# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roster <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 13:14:36 by roster            #+#    #+#              #
#    Updated: 2019/03/14 15:59:23 by roster           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all : $(NAME)

$(NAME):
	@make -C libft
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@echo "\033[34m 〢Creation of $(NAME)\033[0m"

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME) | echo "\x1b[31m ✗ Deleting $(NAME)\x1b[0m"

re:
	@Make fclean
	@Make all

again:
	@Make re
	@Make clean
