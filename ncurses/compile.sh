#!/bin/sh

make -C ../libft/
gcc -lncurses -L ../libft -lft -I ../libft/includes/ -I ../commun/includes -I ../corewar/includes main.c
./a.out
