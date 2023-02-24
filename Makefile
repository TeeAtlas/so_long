# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 12:41:36 by taboterm          #+#    #+#              #
#    Updated: 2023/02/24 13:37:12 by taboterm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# source id
SRCS = so_long.c map_check.c freeing.c freeing_2.c\
	read_map.c display_tile.c player_moves.c elements.c\


OBJS = $(SRCS:%.c=%.o)

# Compiling info
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
MFLAGS = -L${MLX_DIR} -I$(MLX_PATH) -lmlx -lm -framework OpenGL -framework AppKit

# Target output
NAME = so_long

RM = rm -f

# Including Minilibx 
MLX_DIR = ./minilibx_opengl_20191021/
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a
LIBFT = libft/libft.a

# make target executable
$(NAME): $(OBJS)
	make -C ./minilibx_opengl_20191021
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(MFLAGS) -o $(NAME) $(LIBFT)

# Make desired targets
all:	${NAME}

clean:
	make clean -C ./minilibx_opengl_20191021
	make clean -C ./libft

fclean: clean
	make clean -C ./minilibx_opengl_20191021
	make fclean -C ./libft
	/bin/rm -f *.o $(NAME)

re: fclean all

.PHONY: clean fclean all re

