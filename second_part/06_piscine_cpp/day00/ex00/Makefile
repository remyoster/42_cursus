# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roster <roster@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/14 11:21:13 by roster            #+#    #+#              #
#    Updated: 2020/10/08 07:13:42 by roster           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- VARIABLES ---------------------------------#

# Executable

NAME			= megaphone

# Color codes

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

#------------------------------------ FILES -----------------------------------#

## Source files

# main

SRCS			:= megaphone.cpp

#--------------------------------- COMPILATION --------------------------------#

# How files should be compiled.

CC				= clang++

# Compilation flags.

FLAGS			= -Wall -Wextra -Werror -std=c++98

#------------------------------------ RULES -----------------------------------#

# Implicit make rule simply using dependancies to compile the project

all: $(NAME)

$(NAME):
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(FLAGS) -o $(NAME) $(SRCS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"


clean:
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(NAME)

fclean: clean


# Re-compile everything

re: clean all

again:
	@make re
	@make clean

# Protection for rules name

.PHONY: all clean re again