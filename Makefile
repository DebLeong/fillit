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

NAME = fillit

NAMELIB = fillit.a

SRC = 	ft_maketet.c ft_solver.c ft_makelist.c ft_bzboard.c main.c

SRCLIB = ft_putstr.c ft_strlen.c ft_memalloc.c ft_strnew.c ft_bzero.c\
		 ft_strsub.c ft_strdup.c ft_strcmp.c 

OBJ = ft_putstr.o ft_strlen.o ft_memalloc.o ft_strnew.o ft_bzero.o\
	  ft_strsub.o ft_strdup.o ft_strcmp.o

all: $(NAME)

$(NAME): $(NAMELIB)
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) $(NAMELIB)

$(NAMELIB):
	gcc -Wall -Wextra -Werror -c $(SRCLIB)
	ar rcs $(NAMELIB) $(OBJ)
	ranlib $(NAMELIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMELIB)

re: fclean all

.PHONY: clean fclean re all
