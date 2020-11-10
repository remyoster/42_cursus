# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roster <roster@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 09:06:19 by roster            #+#    #+#              #
#    Updated: 2020/10/08 09:37:49 by roster           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- VARIABLES ---------------------------------#

# Executable

NAME			= philo_one

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

# Subdirectories

OBJS_SUBDIRS	:= utils
#OBJS_SUBDIRS	+= sha

#------------------------------------ FILES -----------------------------------#


# Used header at each compilation to check file integrity

INCS			:= incs/philo_one.h
INCS			+= incs/errcode.h

## Source files

# main

SRCS			:= main.c 
SRCS			+= init.c 
SRCS			+= actions.c 
SRCS			+= time.c 
SRCS			+= print.c 
SRCS			+= parser.c 

# utils

SRCS			+= utils/ft_putchar.c 
SRCS			+= utils/ft_putnbr.c 
SRCS			+= utils/ft_putstr.c 
SRCS			+= utils/ft_strlen.c 
SRCS			+= utils/ft_atoi.c 

#----------------------------------- TRICKS -----------------------------------#

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
C_OBJS			= $(addprefix $(D_OBJS), $(OBJS))
C_INCS			= $(foreach include, $(INCS_DIR), -I$(include))
C_SUBDIRS		= $(foreach dir, $(OBJS_SUBDIRS), $(D_OBJS)$(dir))

#--------------------------------- COMPILATION --------------------------------#

# How files should be compiled.

CC				= gcc
OBJS			= $(SRCS:.c=.o)

# Compilation flags.

CFLAGS			= $(C_INCS) -Wall -Wextra -Werror
OFLAGS          = -pthread

#------------------------------------ RULES -----------------------------------#

# Implicit make rule simply using dependancies to compile the project

all: $(OBJS_DIR) $(C_SUBDIRS) $(NAME)

$(NAME): $(C_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) $(OFLAGS) -o $(NAME) $(C_OBJS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Create folders if they don't exists

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(C_SUBDIRS):
	@mkdir -p $(C_SUBDIRS)

# Redefinition of the implicit compilation rule to prompt some informations

$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

# Delete all .o files but keep folders

clean:
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(C_OBJS)

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
