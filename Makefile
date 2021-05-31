# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 22:08:43 by mamaquig          #+#    #+#              #
#    Updated: 2021/05/13 20:5933 by mamaquig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRC			=	$(addprefix src/,			\
					main.c					\
				)\
OBJ			=	$(SRC:.c=.o)
CC			=	gcc
HEADER		=	-Iheader -Ilibft/header
LIB			=	-Llibft
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) $(HEADER) $(LIB) -o $@ $(OBJ) -lft -ltermcap

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

libft:
	make -C libft

norme:
	norminette

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY:	all libft norme clean fclean re
