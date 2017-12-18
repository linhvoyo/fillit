# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilam <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 10:54:22 by lilam             #+#    #+#              #
#    Updated: 2017/12/17 16:38:30 by lilam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FILES = main.c \
		readfile.c \
		shape_validation.c \
		fillit.c

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(FILES)
	@gcc -o $(NAME) -Wall -Wextra -Werror $(FILES)

all: $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
