# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selibrah <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 01:50:10 by selibrah          #+#    #+#              #
#    Updated: 2019/04/21 04:34:57 by selibrah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ./*.c
INC = ./libft.h
CC = gcc -Wall -Wextra -Werror
OBJ =./*.o
all: $(NAME)

$(NAME):
		@$(CC) -c -I $(INC) $(SRC)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
		@rm -rf $(OBJ)

fclean:	clean
		@rm -rf $(NAME)
re:	fclean all
