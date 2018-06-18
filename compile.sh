#!/bin/zsh
make re
make clean
gcc main.c -g libftprintf.a -I ./libft/includes
echo "\n\n"
./a.out
