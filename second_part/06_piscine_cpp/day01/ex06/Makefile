# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roster <roster@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/14 11:21:13 by roster            #+#    #+#              #
#    Updated: 2020/10/09 07:43:27 by roster           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- VARIABLES ---------------------------------#

# Executable

NAME			= war

# Color codes

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

#--------------------------------- DIRECTORIES  -------------------------------#

# Main

OBJS_DIR		= objs

#------------------------------------ FILES -----------------------------------#

## Source files

# main

SRCS			:= main.cpp
SRCS			+= Weapon.cpp
SRCS			+= HumanA.cpp
SRCS			+= HumanB.cpp

#----------------------------------- TRICKS -----------------------------------#

D_OBJS			= $(addsuffix /, $(OBJS_DIR))
CPP_OBJS		= $(addprefix $(D_OBJS), $(OBJS))

#--------------------------------- COMPILATION --------------------------------#

# How files should be compiled.

CC				= clang++
OBJS			= $(SRCS:.cpp=.o)

# Compilation flags.

CPPFLAGS			= -Wall -Wextra -Werror -std=c++98

#------------------------------------ RULES -----------------------------------#

# Implicit make rule simply using dependancies to compile the project

all: $(OBJS_DIR) $(NAME)

$(NAME): $(CPP_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CPPFLAGS) -o $(NAME) $(CPP_OBJS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Create folders if they don't exists

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Redefinition of the implicit compilation rule to prompt some informations

$(D_OBJS)%.o: %.cpp
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(CPP_OBJS)

# Delete executable and objs folder

fclean: clean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(NAME)
	@rm -rf $(OBJS_DIR)

# Re-compile everything

re: clean all

again:
	@make re
	@make clean

# Protection for rules name

.PHONY: all clean fclean re again