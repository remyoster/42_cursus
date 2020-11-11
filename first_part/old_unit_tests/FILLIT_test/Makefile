# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roster <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 09:09:38 by roster            #+#    #+#              #
#    Updated: 2019/01/10 12:07:14 by roster           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

# Program name
NAME=can_you_feel_it

# Colors
GREEN= \033[0;32m
BLUE= \033[0;34m
RED= \033[0;31m
YELLOW= \033[0;33m

#Source and objects
SRCS= *.c
OBJS= $(SRCS:.c=.o)

# Flags
FLAGS= -Wall -Wextra -Werror

# Default make
all: $(NAME)

$(NAME):
	@make -C GEN
	@make -C ../
	@gcc -c $(FLAGS) $(SRCS)
	@gcc $(OBJS) -o $(NAME)
	@printf "$(GREEN) ✓ Creation of $(NAME)\n"

clean:
	@make clean -C GEN
	@make clean -C ../
	@/bin/rm -f $(OBJS)
	@printf "$(BLUE) ✗ Deletion of $(OBJS)\n"

fclean: clean
	@make fclean -C GEN
	@make fclean -C ../
	@/bin/rm -f $(NAME)
	@printf "$(RED) ✗ Deletion of $(NAME)\n"

re:
	@Make fclean
	@Make again
	@Make all

again:
	@find . -type f -name "map*" -exec rm {} \;
	@printf "$(YELLOW) ✗ Deletion of map files\n"

