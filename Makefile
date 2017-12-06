# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toliver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/15 16:37:55 by toliver           #+#    #+#              #
#    Updated: 2017/12/06 17:57:26 by toliver          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FILES = main.c \
		parser.c \
		init.c \
		keyboard.c \
		maps.c \
		isprintable.c \
		print.c \
		matrix_apply.c \
		moving.c \
		button.c \
		putline.c \
		img.c \
		joinfunct.c \
		mouse1.c 

OBJ = $(FILES:.c=.o)

INCLUDES = -I. -I./libft/includes

LIB = libft/libft.a 

FLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ) #fdf.h
	make -C libft/
	gcc -o $(NAME) $(OBJ) $(FLAGS) $(MLX) $(LIB) $(INCLUDES)

%.o: %.c
	gcc -o $@ -c $< $(FLAGS) $(INCLUDES)

clean:
	make clean -C libft/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all
