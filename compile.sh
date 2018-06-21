#!/bin/bash
make re
make clean
gcc main.c -g -o printf libftprintf.a -I ./libft/includes
echo "\n\n"
./printf
