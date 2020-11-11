# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roster <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 16:29:11 by roster            #+#    #+#              #
#    Updated: 2019/01/10 11:21:52 by roster           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = GNL

SRCS = main_no_fds.c \
	   ../get_next_line.c \

OBJS = $(SRCS:.c=.o)

OBJS2 = main_no_fds.o \
		get_next_line.o

FLAGS = -Wall -Wextra -Werror

LIB = ../libft/libft.a

INCLUDE = ../get_next_line.h

all: $(EXEC)

$(EXEC):
	@make -C ../libft
	gcc -c $(FLAGS) $(SRCS) -I $(INCLUDE) 
	gcc $(OBJS2) $(LIB) -o $(EXEC)

clean:
	@make clean -C ../libft
	/bin/rm -f $(OBJS2)

fclean: clean
	@make fclean -C ../libft
	/bin/rm -f $(EXEC)

re:
	Make fclean
	Make all

