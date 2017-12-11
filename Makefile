# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilam <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 10:54:22 by lilam             #+#    #+#              #
#    Updated: 2017/12/11 11:27:14 by lilam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILES = readfile.c shape_validation.c fillit.c 

all:
	@gcc -o $(NAME) -Wall -Wextra -Werror $(FILES)

clean:
	@rm -rf ft*.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
