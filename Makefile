# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dleong <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/19 22:50:05 by dleong            #+#    #+#              #
#*   Updated: 2017/09/19 23:43:41 by dleong           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fillit.a

FILES = ft_maketet.c ft_putstr.c ft_strlen.c ft_memalloc.c ft_strnew.c \
		ft_bzero.c ft_strsub.c

OBJ = *.o

all: $(NAME)

$(OBJ): $(FILES)
	gcc -Wall -Wextra -Werror -c $(FILES)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
