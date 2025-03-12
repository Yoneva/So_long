# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amsbai <amsbai@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/01 18:34:48 by amsbai            #+#    #+#              #
#    Updated: 2025/03/12 21:22:00 by amsbai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = $(SRC:.c=.o)
MLX = ./MLX42
NAME = so_long
SRC = main.c parsing.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	  Utils/ft_realloc.c Utils/ft_memmove.c Utils/double_arr.c path.c window_set.c \
	  player_handling.c manage_collect.c parsing_utils.c
CFLAGS = -Wall -Wextra -Werror
HEADER = so_long.h

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) ../MLX/MLX42/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -I$(MLX) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY : clean