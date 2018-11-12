# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmahloko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/17 11:58:04 by mmahloko          #+#    #+#              #
#    Updated: 2018/09/27 17:52:29 by mmahloko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OPT = -c

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_del.c ft_isalnum.c ft_isascii.c ft_isdigit.c \
	  ft_islower.c ft_isprint.c ft_isupper.c ft_itoa.c ft_lst_split.c \
	  ft_lstadd.c ft_lstadd_end.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
	  ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
	  ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
	  ft_numlen.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
	  ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c \
	  ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
	  ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	  ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
	  ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	  ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	  ft_tolower.c ft_toupper.c ft_isalpha.c ft_strdel.c ft_lstprint.c \
	  ft_lstcount.c get_next_line.c ft_arraydel_s.c ft_atol.c \
	  ft_array_join_s.c ft_swap.c ft_array_join2.c

OBJ = ft_atoi.o ft_bzero.o ft_del.o ft_isalnum.o ft_isascii.o ft_isdigit.o \
	  ft_islower.o ft_isprint.o ft_isupper.o ft_itoa.o ft_lst_split.o \
	  ft_lstadd.o ft_lstadd_end.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o \
	  ft_lstmap.o ft_lstnew.o ft_memalloc.o ft_memccpy.o ft_memchr.o \
	  ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o \
	  ft_numlen.o ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o \
	  ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o \
	  ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdup.o \
	  ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o \
	  ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o \
	  ft_strncpy.o ft_strndup.o ft_strnequ.o ft_strnew.o ft_strnstr.o \
	  ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o \
	  ft_tolower.o ft_toupper.o ft_isalpha.o ft_strdel.o ft_lstprint.o \
	  ft_lstcount.o get_next_line.o ft_arraydel_s.o ft_atol.o \
	  ft_array_join_s.o ft_swap.o ft_array_join2.o

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(OPT) $(SRC)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

n:
	norminette -R CheckForbiddenSourceHeader ft_s*
	norminette -R CheckForbiddenSourceHeader ft_p*
	norminette -R CheckForbiddenSourceHeader ft_i*
	norminette -R CheckForbiddenSourceHeader ft_mem*
	norminette -R CheckForbiddenSourceHeader ft_a*
	norminette -R CheckForbiddenSourceHeader ft_b*
	norminette -R CheckForbiddenSourceHeader ft_l*
	norminette -R CheckForbiddenSourceHeader ge*
	norminette -R CheckForbiddenSourceHeader libft.h
