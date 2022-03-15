# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 19:32:44 by lkrebs-l          #+#    #+#              #
#    Updated: 2022/02/26 17:29:56 by lkrebs-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = api

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror

SRC =	src/api_utils.c \
		src/api.c \
		src/log.c \
		src/mysql.c \
		src/reply.c \
		src/routes.c \
		src/utils.c \
		mongoose/mongoose.c 

OBJ = $(SRC:.c=.o)

RM = rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmysqlclient -o $(NAME)

re: fclean $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
