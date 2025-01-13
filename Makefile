# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nikitadorofeychik <nikitadorofeychik@st    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 21:48:16 by nikitadorof       #+#    #+#              #
#    Updated: 2024/11/21 21:58:53 by nikitadorof      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = utils.c hexa.c ft_printf.c ft_nbr.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Werror -Wextra -Wall
CC = gcc
LIB = ar -rsc
RM = rm -f


all: $(NAME)

$(NAME): $(OBJ) 
	$(LIB) $(NAME) $(OBJ)

%.o: %.c, ft_printf.h Makefile
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: clean fclean re