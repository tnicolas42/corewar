# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 19:11:27 by tnicolas          #+#    #+#              #
#    Updated: 2018/02/09 14:23:22 by tnicolas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make -C asm

clean:
	@make -C asm clean

fclean:
	@make -C asm fclean

re:
	@make -C asm re

exec: all
	@./test.sh

norm:
	@make -C libft norm
	@make -C asm norm

.PHONY: all clean fclean re exec norm
