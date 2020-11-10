# Executable's name 

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME		= libft_malloc_$(HOSTTYPE).so
LINKEDNAME	= libft_malloc.so

# All the directories needed to know where files should be

OBJDIR		= objs/
SRCDIR		= srcs/
LFTDIR		= libft/
INCDIR		= ./incs/ ./libft/

# Source files 

SRC			= malloc.c free.c realloc.c calloc.c \
				show_alloc_mem.c utils.c lists.c print.c

LFT			= ./libft/libft.a

# Some tricks in order to get the makefile doing his job

CSRC		= $(addprefix $(SRCDIR), $(SRC))
COBJ		= $(addprefix $(OBJDIR), $(OBJ))
SUBDIRS		= $(foreach dir, $(OBJSUBDIRS), $(OBJDIR)$(dir))
INCLUDES	= $(foreach include, $(INCDIR), -I$(include))

# How files should be compiled with set flags

CC			= gcc
OBJ			= $(SRC:.c=.o)
LIBS		= -L $(LFTDIR) -lft
CFLAGS		= $(INCLUDES) -Wall -Wextra -Werror

# Color codes

RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

# Check if object directory exists, build libft and then the Project

all: $(SUBDIRS) $(NAME)

$(NAME): $(LFT) $(OBJDIR) $(COBJ)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC)  $(CFLAGS) -shared -o $(NAME) $(COBJ) $(LIBS) 
	@ln -sf $(NAME) $(LINKEDNAME)
	@echo "$(GREEN)***  Dynamic library $(NAME) successfully compiled  ***\n$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(SUBDIRS):
	@mkdir -p $(SUBDIRS)
	# Redefinition of implicit compilation rule to prompt some colors and file
	# names during the said compilation

#fPIC is for global use in shared libraries
$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Compilation rule for function library

$(LFT):
	@make -sC $(LFTDIR) -j


# Deleting all .o files and then the directory where they were located

clean:
	@make -sC $(LFTDIR) clean
	@echo "$(GREEN)***  Deleting all object from $(NAME) ... ***\n$(RESET)"
	@rm -f $(COBJ)

# Deleting the executable after cleaning up all .o files

fclean: clean
	@make -sC $(LFTDIR) fclean
	@echo "$(GREEN)***  Deleting executable file from $(NAME) ... ***\n$(RESET)"
	@rm -f $(NAME) $(LINKEDNAME)
	@rm -rf $(OBJDIR)

re: fclean all

again : re clean

.PHONY: all clean fclean re
