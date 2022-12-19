# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taboterm <taboterm@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 15:17:12 by taboterm          #+#    #+#              #
#    Updated: 2022/12/19 15:34:44 by taboterm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target output
NAME = so_long

# source id
SRCS = so_long_window.c

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

RM = rm -f
# Including Minilibx 
MLX_DIR = ./minilibx_opengl_20191021
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a

# Compiling info
CC = gcc
CFLAGS = -Wall -Werror -Wextra 
MFLAGS = -L${MLX_DIR} -I$(MLX_PATH) -lmlx -lm -framework OpenGL -framework AppKit

# make target executable
$(NAME): $(OBJS) $(GNL_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MFLAGS)  -o $(NAME) 
# Make desired targets
all:	${NAME}

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f *.o $(NAME)

re: fclean all

.PHONY: clean fclean all re
