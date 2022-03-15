# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 14:11:32 by lkrebs-l          #+#    #+#              #
#    Updated: 2022/02/23 19:37:42 by lkrebs-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cli

CC = gcc

CFLAGS = -g3

SRC =	src/check_arguments.c \
		src/cli.c \
		src/count_methods.c \
		src/init_cli.c \
		src/print.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

re: fclean $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
