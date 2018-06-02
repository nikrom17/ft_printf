# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nroman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/26 12:48:11 by nroman            #+#    #+#              #
#    Updated: 2018/05/30 10:51:33 by nroman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME = no name needed because ft_printf is a function
NAME_LIB = libftprintf.a
CC = gcc
HEADERS = libft/includes
FLAGS = -Wall -Werror -c
OPTION = -I $(HEADERS) -g
LIBFT = -L libft/ -lftprintf
DEPENDENCY = 	ft_printf.c \
				handle_functions.c
OBJ = *.o

all: $(NAME_LIB)

$(NAME_LIB): $(DEPENDENCY)
	make -C libft/
	cp libft/libft.a ./$(NAME_LIB)
	$(CC) $(OPTION) $(FLAGS) $(DEPENDENCY)
	ar rc $(NAME_LIB) $(OBJ)
	ranlib $(NAME_LIB)
	gcc main.c -Wall -Werror -g libftprintf.a -I ./libft/includes

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME_LIB)

re: fclean all
