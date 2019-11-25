# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: relkassm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 13:49:30 by relkassm          #+#    #+#              #
#    Updated: 2019/11/25 15:02:18 by relkassm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../fdf

FLAG = -Werror -Wextra -Wall

SRC = main.c check_file.c store.c fdf.c line.c


OBJ = main.o check_file.o store.o fdf.o line.o


BIN = ../libft/libft.a ../minilibx_macos/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) $(OBJ) $(BIN) -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
