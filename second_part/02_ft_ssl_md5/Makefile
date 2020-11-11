# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roster <roster@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/21 09:49:22 by roster            #+#    #+#              #
#    Updated: 2020/04/24 13:38:31 by roster           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------- VARIABLES ---------------------------------#

# Executable

NAME			= ft_ssl

# Color codes

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

#--------------------------------- DIRECTORIES  -------------------------------#

# Libraries

LFT_DIR			= libft

# Main

SRCS_DIR		= srcs
OBJS_DIR		= objs

# Header

INCS_DIR		:= incs
INCS_DIR		+= libft

# Subdirectories

OBJS_SUBDIRS	:= md5
OBJS_SUBDIRS	+= sha

#------------------------------------ FILES -----------------------------------#

# Libft

LFT				= $(LFT_DIR)/libft.a

# Used header at each compilation to check file integrity

INCS			:= incs/ft_ssl.h
INCS			+= incs/md5.h
INCS			+= incs/sha.h

## Source files

# main

SRCS			:= main.c 
SRCS			+= hash.c 
SRCS			+= parser.c
SRCS			+= print.c 
SRCS			+= print_err.c 
SRCS			+= usage.c
SRCS			+= utils.c

# md5

SRCS			+= md5/md5.c 
SRCS			+= md5/md5_basic_fcts.c 
SRCS			+= md5/md5_cst.c 
SRCS			+= md5/md5_buf_ope.c 

# sha2

SRCS			+= sha/sha_cst.c
SRCS			+= sha/sha_basic_fcts.c
SRCS			+= sha/sha256.c
SRCS			+= sha/sha256_buf_ope.c
SRCS			+= sha/sha256_rotr_fcts.c
SRCS			+= sha/sha512.c
SRCS			+= sha/sha512_rotr_fcts.c
SRCS			+= sha/sha512_buf_ope.c

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

# Linked libraries at compile time.

LIBS			+= -L $(LFT_DIR) -lft

# Compilation flags.

CFLAGS			= $(C_INCS) -Wall -Wextra -Werror

#------------------------------------ RULES -----------------------------------#

# Implicit make rule simply using dependancies to compile the project

all: $(OBJS_DIR) $(C_SUBDIRS) $(NAME)

$(NAME): $(LFT) $(C_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Libft installion using his own Makefile.

$(LFT):
	@make -sC $(LFT_DIR) -j

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
	@make -sC $(LFT_DIR) clean
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(C_OBJS)

# Delete executable, library and objs folder

fclean: clean
	@make -sC $(LFT_DIR) fclean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(NAME)
	@rm -rf $(OBJS_DIR)
	@rm -f testfile resfile


# Re-compile everything

re: fclean all

again:
	@make re
	@make clean

# Protection for rules name

.PHONY: all clean fclean re
