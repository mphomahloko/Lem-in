# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 11:22:36 by mmahloko          #+#    #+#              #
#    Updated: 2018/09/29 14:18:37 by mmahloko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = ./src/adding_rooms.c ./src/ft_error.c ./src/input.c ./src/lem_in.c\
	  ./src/reading_map.c ./src/valid_farm.c ./src/garbage.c

CFLAGS = -Wall -Wextra -Werror

OBJ = adding_rooms.o ft_error.o input.o lem_in.o reading_map.o valid_farm.o\
	  garbage.o

all : $(NAME)

$(NAME) :
	@make -C libft
	@gcc -c $(CFLAGS) $(SRC)
	@gcc $(OBJ) $(CFLAGS) ./src/main.c libft/libft.a -o $(NAME)

clean :
	@make clean -C libft
	@/bin/rm -f $(OBJ)

fclean : clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re : fclean all

n :
	norminette -R CheckForbiddenSourceHeader $(SRC)
