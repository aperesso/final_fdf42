# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/13 19:12:18 by alexia            #+#    #+#              #
#    Updated: 2018/01/11 20:20:50 by aperesso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = toolbox.a

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

CC = gcc
C_FLAGS = -Wall -Wextra -Werror -g
# FRAM = -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext
# FRAM = -framework OpenGL -framework AppKit minilibx/libmlx.a
# FRAM = -L minilibx -I minilibx -lmlx -framework OpenGL -framework AppKit -g

OBJ_PATH = ./obj/
INC_PATH = ./includes/
SRC_PATH = ./src/

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = toolbox.h
SRC_NAME = 	create_matrix.c \
			set_identity.c \
			mult_matrix.c \
			translate.c \
			rotate_matrix.c \
			scale.c \
			transformation_matrix.c \
			view_matrix.c \
			projection_matrix.c \
			new_mesh.c \
			viewport_matrix.c \
			set_vector_4d.c\
			set_vector_3d.c\
			map.c\
			set_vector_2d.c\

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME)  $^ $@ 
		@ranlib $(NAME)
		@echo "\033[1;34mToolbox\t\t\033[1;33mCompilation\t\t\033[0;32m[OK]\033[0m"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<

clean:
		@rm -rf $(OBJ_PATH)
		@echo "\033[1;34mToolbox\t\t\033[1;33mCleaning obj\t\t\033[0;32m[OK]\033[0m"

fclean: clean
		@rm -f $(NAME)
		@echo "\033[1;34mToolbox\t\t\033[1;33mCleaning lib\t\t\033[0;32m[OK]\033[0m"

re: fclean all