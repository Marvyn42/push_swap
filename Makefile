# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 22:08:43 by mamaquig          #+#    #+#              #
#    Updated: 2021/08/19 18:10:24 by mamaquig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRC			=	$(addprefix src/,				\
					main.c						\
					utils.c						\
					check_parsing.c				\
				)								\
				$(addprefix src/operations/,	\
					push.c						\
					reverse.c					\
					rotate.c					\
					swap.c						\
				)
OBJ			=	$(SRC:.c=.o)
CC			=	gcc
HEADER		=	-Iheader
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(HEADER) $(LIB) -o $@ $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

norme:
	norminette

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all norme clean fclean re
