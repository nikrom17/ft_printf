#
#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nroman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 10:55:49 by nroman            #+#    #+#              #
#    Updated: 2018/03/28 10:25:25 by nroman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
PATH_SRC = 
HEADER = includes/
FLAG = -Wall -Wextra -Werror  -c
OPTION = -I $(HEADER) -g 
DEPENDENCY = $(PATH_SRC)*.c
OBJ = *.o

all: $(NAME)

$(NAME): $(DEPENDENCY)
	$(CC) $(OPTION) $(FLAG) $(DEPENDENCY)
	ar rc $(NAME) $(OBJ)
#	ranlib $(NAME)

clean:
	rm -f $(OBJ)
fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
re: fclean all
