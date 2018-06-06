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
NAME = libftprintf.a
CC = gcc
HEADERS = libft/includes
FLAGS = -Wall -Werror -c
OPTION = -I $(HEADERS) -g
LIBFT = -L libft/ -lftprintf
DEPENDENCY = 	ft_printf.c \
				handle_functions.c
OBJ = *.o

all: $(NAME)

$(NAME): $(DEPENDENCY)
	make -C libft/
	cp libft/libft.a ./$(NAME)
	$(CC) $(OPTION) $(FLAGS) $(DEPENDENCY)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	gcc main.c -g libftprintf.a -I ./libft/includes

clean:
	rm -f $(OBJ) libft/$(OBJ)

fclean:
	rm -f $(OBJ) $(NAME) libft/$(OBJ) libft/libft.a



re: fclean all
