# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/27 11:25:13 by gduval            #+#    #+#              #
#    Updated: 2017/07/27 11:25:16 by gduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT_NAME = libft.a
LIBFT_PATH = ./libft/
LIBFT = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

SRC_PATH = ./srcs/
SRC_NAME = main.c					\
			keyhook.c				\
			init_struct.c			\
			mlx_pixel_to_image.c	\
			draw_julia.c			\
			draw_mandelbrot.c		\
			draw_tricorn.c			\
			others.c				\

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(SRC_NAME:.c=.o)

HEADER_PATH = ./includes/
HEADER_NAME = fractole.h
HEADER = $(addprefix $(HEADER_PATH), $(HEADER_NAME))

FLAGS = -framework OpenGL -framework Appkit -Werror -Wextra -Wall
CC = gcc

all: $(NAME)

$(NAME) :
	@echo "\033[93m----------------------------------\033[0m"
	@echo "\033[93m-      FRACT'OL COMPILATION      -\033[0m"
	@echo "\033[93m----------------------------------\033[0m"
	@make -C libft
	@$(CC) minilibx_macos/libmlx.a $(FLAGS) $(LIBFT) $(SRC) -o $(NAME)
	@echo "\033[93m-              done              -\033[0m"

opti:
	@echo "\033[93m----------------------------------\033[0m"
	@echo "\033[93m-   FRACT'OL COMPILATION (OPTI)  -\033[0m"
	@echo "\033[93m----------------------------------\033[0m"
	@make -C libft
	@$(CC) minilibx_macos/libmlx.a $(FLAGS) $(LIBFT) $(SRC) -o $(NAME)
	@echo "\033[93m-              done              -\033[0m"

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
