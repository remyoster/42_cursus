# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roster <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 13:08:20 by roster            #+#    #+#              #
#    Updated: 2019/02/12 14:15:36 by roster           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

#Colors 
GREEN = \033[0;32m
BLUE = \033[0;94m
RED = \033[0;31m
CYAN = \033[0;36m

NAME = fdf

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a \

INCLUDES = fdf.h

FRAME = -framework OpenGL -framework AppKit

SRCS = srcs/main/main.c \
	   srcs/main/ft_create_map.c \
	   srcs/parse/ft_check_file.c \
	   srcs/main/ft_usage.c \
	   srcs/print/ft_bresenham.c \
	   srcs/print/ft_fill_pixel.c \
	   srcs/print/ft_fill_window_iso.c \
	   srcs/print/ft_fill_window_para.c \
	   srcs/event/ft_deal_key.c \
	   srcs/print/ft_legends.c \
	   srcs/event/ft_colors.c \
	   srcs/main/ft_hexa_to_rgb.c \
	   srcs/main/ft_cmp_rgb.c \
	   srcs/colors/ft_mountain.c \
	   srcs/event/ft_degrade.c \
	   srcs/colors/ft_rainbow.c \
	   srcs/colors/ft_reverse_rainbow.c \
	   srcs/main/ft_atoi_base_fdf.c \
	   srcs/main/ft_srch_extrem_val_fdf.c \
	   srcs/event/ft_arrow.c \
	   srcs/main/ft_gap.c \
	   srcs/event/ft_high.c \
	   srcs/event/ft_zoom.c \
	   srcs/event/ft_coloring.c \
	   srcs/event/ft_recenter.c \
	   srcs/event/ft_change_proj.c 

OBJS = main.o \
	   ft_create_map.o \
	   ft_check_file.o \
	   ft_usage.o \
	   ft_bresenham.o \
	   ft_fill_pixel.o \
	   ft_fill_window_iso.o \
	   ft_fill_window_para.o \
	   ft_deal_key.o \
	   ft_legends.o \
	   ft_colors.o \
	   ft_hexa_to_rgb.o \
	   ft_cmp_rgb.o \
	   ft_mountain.o \
	   ft_degrade.o \
	   ft_rainbow.o \
	   ft_reverse_rainbow.o \
	   ft_atoi_base_fdf.o \
	   ft_srch_extrem_val_fdf.o \
	   ft_arrow.o \
	   ft_high.o \
	   ft_zoom.o \
	   ft_coloring.o \
	   ft_recenter.o \
	   ft_gap.o \
	   ft_change_proj.o 

all: $(NAME)

$(NAME):
	@echo "$(CYAN)###################"
	@echo "##COMPILING LIBFT##"
	@echo "###################\033[0;39m"
	@make -C libft
	@echo "$(CYAN) /----------------\\"
	@echo "|  COMPILING FDF   |"
	@echo " \----------------/\033[0;39m"
	@gcc -c $(FLAGS) $(SRCS) -I $(INCLUDES)
	@echo "$(BLUE) ︻デ═一 ▸ Object files"
	@gcc $(OBJS) -L /usr/local/lib/ -lmlx $(LIB) $(FRAME) -o $(NAME)
	@echo "$(GREEN) ︻デ═一 ▸ Creation of $(NAME)"

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re:
	@Make fclean
	@Make all
