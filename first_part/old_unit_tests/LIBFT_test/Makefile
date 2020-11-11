# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roster <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 12:05:33 by roster            #+#    #+#              #
#    Updated: 2018/12/09 15:52:53 by roster           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = Rosterlinette

SRCS1 = $(wildcard srcs/*.c) \
	   $(wildcard *.c)
	   
OBJS1 = $(SRCS1:.c=.o)

OBJS2 = $(wildcard *.o)

FLAGS1 = -Wall -Wextra -Werror

INCLUDE = rosterlinette.h

LIB = ../../libft.a

LIBFT_DIR = ../../../libft

all: $(EXEC)

$(EXEC):
	@echo "Execution of libft's cmd : make"
	@(cd $(LIBFT_DIR) && $(MAKE)) 
	@gcc $(FLAGS1) $(SRCS1) $(LIB) -o $(EXEC)

clean:
	@/bin/rm -f $(EXEC) | echo "Deleting Rosterlinette"
	@echo "Execution of libft's cmd : make clean"
	@(cd $(LIBFT_DIR) && $(MAKE) $@)

fclean: clean
	@echo "Execution of libft's cmd : make fclean"
	@(cd $(LIBFT_DIR) && $(MAKE) $@)

re: 
	Make fclean 
	Make all
