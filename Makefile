# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilam <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 10:54:22 by lilam             #+#    #+#              #
#    Updated: 2017/12/12 22:06:24 by lilam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILES = main.c \
		readfile.c \
		shape_validation.c \
		fillit.c

all:
	@gcc -o $(NAME) -Wall -Wextra -Werror $(FILES)

clean:
	@rm -rf ft*.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
