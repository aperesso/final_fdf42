# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 17:13:32 by aperesso          #+#    #+#              #
#    Updated: 2018/01/11 19:48:59 by aperesso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

cc = gcc
C_FLAGS = -Wall -Wextra -Werror -g
FRAM = -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext
# FRAM = -framework OpenGL -framework AppKit minilibx/libmlx.a
# FRAM =  -L minilibx -I minilibx -lmlx -framework OpenGL -framework AppKit -g

OBJ_PATH = ./obj/
LFT_PATH = ./libft/
TOOL_PATH = ./math_toolbox/
INC_PATH = ./includes/
SRC_PATH = ./sources/

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fdf.h
SRC_NAME = main.c get_next_line.c loader.c init.c processMesh.c key_hook.c draw.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

.PHONY: all clean fclean re

all: 
	@make -C $(LFT_PATH)
	@make -C $(TOOL_PATH)
	@make $(NAME)

$(NAME): $(OBJ)

		@$(CC) -o $(NAME) $(FRAM) -L $(LFT_PATH) -lft  math_toolbox/toolbox.a $^ -o $@ 
		@echo "\033[1;35mFdf\t\t\033[1;36mReady\t\t\t\033[0;31m[♥]\033[0m"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(C_FLAGS) $(INC) -o $@ -c $<

clean:
		@make -C $(LFT_PATH) clean
		@make -C $(TOOL_PATH) clean
		@rm -rf $(OBJ_PATH)
		@echo "\033[1;35mFdf\t\t\033[1;36mCleaning obj\t\t\033[0;31m[OK]\033[0m"

fclean: clean
		@make -C $(LFT_PATH) fclean
		@make -C $(TOOL_PATH) fclean
		@rm -f $(NAME)
		@echo "\033[1;35mFdf\t\t\033[1;36mCleaning fdf\t\t\033[0;31m[OK]\033[0m"

re: fclean
	make
