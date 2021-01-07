# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roster <roster@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 09:06:19 by roster            #+#    #+#              #
#    Updated: 2020/12/08 08:56:17 by roster           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- VARIABLES ---------------------------------#

# Executable

NAME			= avm

# Color codes

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

#--------------------------------- DIRECTORIES  -------------------------------#

# Main

SRCS_DIR		= srcs
OBJS_DIR		= objs

# Header

INCS_DIR		:= incs


#------------------------------------ FILES -----------------------------------#


# Used header at each compilation to check file integrity

INCS			:= incs/Dictionary.hpp
INCS			+= incs/Error.hpp
INCS			+= incs/BaseError.hpp
INCS			+= incs/SyntaxError.hpp
INCS			+= incs/LogicError.hpp
INCS			+= incs/Factory.hpp
INCS			+= incs/IOperand.hpp
INCS			+= incs/TOperand.hpp
INCS			+= incs/Lexer.hpp
INCS			+= incs/Parser.hpp
INCS			+= incs/Printer.hpp
INCS			+= incs/Token.hpp
INCS			+= incs/Resolver.hpp

## Source files

# main

SRCS			:= main.cpp
SRCS			+= Dictionary.cpp
SRCS			+= Lexer.cpp
SRCS			+= Parser.cpp
SRCS			+= Token.cpp
SRCS			+= Printer.cpp
SRCS			+= Factory.cpp
SRCS			+= Error.cpp
SRCS			+= BaseError.cpp
SRCS			+= SyntaxError.cpp
SRCS			+= LogicError.cpp
SRCS			+= Resolver.cpp

#----------------------------------- TRICKS -----------------------------------#

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
CPP_OBJS		= $(addprefix $(D_OBJS), $(OBJS))
CPP_INCS		= $(foreach include, $(INCS_DIR), -I$(include))

#--------------------------------- COMPILATION --------------------------------#

# How files should be compiled.

CC				= clang++
OBJS			= $(SRCS:.cpp=.o)

# Compilation flags.

CPPFLAGS			= $(CPP_INCS) -Wall -Wextra -Werror -std=c++11

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

$(D_OBJS)%.o: $(D_SRCS)%.cpp $(INCS)
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CPPFLAGS) -c $< -o $@

# Delete all .o files but keep folders

clean:
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(CPP_OBJS)

# Delete executable and objs folder

fclean: clean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(NAME)
	@rm -rf $(OBJS_DIR)


# Re-compile everything

re: fclean all

again:
	@make re
	@make clean

# Protection for rules name

.PHONY: all clean fclean re again
