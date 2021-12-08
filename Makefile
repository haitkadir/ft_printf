# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 16:04:21 by haitkadi          #+#    #+#              #
#    Updated: 2021/12/02 16:04:23 by haitkadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a


SRC = ft_printf.c ./ft_utils/ft_printf_utils.c ./ft_utils/ft_strchr.c \
	 ./ft_utils/ft_atoi.c ./ft_utils/ft_isdigit.c ./ft_utils/ft_isalpha.c \
	 ./ft_utils/ft_numlen.c ft_process_d.c ./ft_utils/ft_tolower.c \
	 ./ft_utils/ft_itoa.c ./ft_utils/ft_calloc.c ./ft_utils/ft_strdup.c \
	 ./ft_utils/ft_strlen.c ./ft_utils/ft_bzero.c

SRC_OBJECTS = $(SRC:%.c=%.o)

$(NAME): $(SRC_OBJECTS)
	@ar rcs $(NAME) $(SRC_OBJECTS)

all: $(NAME)

%.o:%.c ft_printf.h
	@$(CC) $(CFLAGS) -o $@ -c $<

bonus: all

clean:
	@rm -f $(SRC_OBJECTS)

fclean: clean
	@rm -f $(NAME) a.out

re: fclean all

compile:
	@$(CC) main.c $(SRC) -g
	@./a.out | cat -e

.PHONY: all clean fclean re compile