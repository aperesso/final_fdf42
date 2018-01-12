# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperesso <aperesso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/13 19:12:18 by alexia            #+#    #+#              #
#    Updated: 2017/04/17 19:15:22 by aperesso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SOURCES = ft_bzero.c\
		  ft_isalnum.c\
		  ft_atoi.c\
		  ft_isalpha.c\
		  ft_isascii.c\
		  ft_isdigit.c\
		  ft_isprint.c\
		  ft_memccpy.c\
		  ft_memcmp.c\
		  ft_memcpy.c\
		  ft_memchr.c\
		  ft_putnbr.c\
		  ft_memmove.c\
		  ft_memset.c\
		  ft_strcat.c\
		  ft_strchr.c\
		  ft_strcmp.c\
		  ft_strcpy.c\
		  ft_strdup.c\
		  ft_strlen.c\
		  ft_strncat.c\
		  ft_strncmp.c\
		  ft_strncpy.c\
		  ft_strchr.c\
		  ft_putnbr_fd.c\
		  ft_lstnew.c\
		  ft_lstdelone.c\
		  ft_lstdel.c\
		  ft_lstiter.c\
		  ft_strlcat.c\
		  ft_lstmap.c\
		  ft_lstadd.c\
		  ft_strstr.c\
		  ft_strnstr.c\
		  ft_tolower.c\
		  ft_toupper.c\
		  ft_strrchr.c\
		  ft_memalloc.c\
		  ft_memdel.c\
		  ft_strnew.c\
		  ft_strdel.c\
		  ft_strclr.c\
		  ft_striter.c\
		  ft_striteri.c\
		  ft_strmap.c\
		  ft_strmapi.c\
		  ft_strequ.c\
		  ft_strnequ.c\
		  ft_strsub.c\
		  ft_strjoin.c\
		  ft_strtrim.c\
		  ft_strsplit.c\
		  ft_itoa.c\
		  ft_putchar.c\
		  ft_putstr.c\
		  ft_putendl.c\
		  ft_putchar_fd.c\
		  ft_putstr_fd.c\
		  ft_putendl_fd.c\



HEADERS = libft.h

OBJECT = $(SOURCES:.c=.o)

$(NAME):
	@$(CC) $(FLAGS) -c $(SOURCES)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)
	@echo "\033[1;34mLibft\t\t\033[1;33mCompilation\t\t\033[0;32m[OK]\033[0m"

all: $(NAME)

clean:
	@rm -rf $(OBJECT)
	@echo "\033[1;34mLibft\t\t\033[1;33mCleaning obj\t\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -fr $(NAME)
	@echo "\033[1;34mLibft\t\t\033[1;33mCleaning lib\t\t\033[0;32m[OK]\033[0m"

re: fclean all
