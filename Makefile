# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svassal <svassal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 15:25:41 by aljourda          #+#    #+#              #
#    Updated: 2016/03/22 15:18:45 by svassal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
SRC=ft_display.c ft_parse.c ft_solver.c ft_tetriminos.c ft_place.c main.c
OBJ=$(SRC:.c=.o)
LDFLAGS=-Wall -Wextra -Werror

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	gcc -c $(LDFLAGS) $^ -o $@
