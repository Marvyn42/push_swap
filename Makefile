# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 22:08:43 by mamaquig          #+#    #+#              #
#    Updated: 2021/09/14 20:27:59 by mamaquig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
SRC			=	$(addprefix src/,				\
					check_parsing.c				\
					main.c						\
					small_size.c				\
					quick_sort.c				\
					stack_a.c					\
					stack_b.c					\
				)								\
				$(addprefix src/operations/,	\
					push.c						\
					reverse.c					\
					rotate.c					\
					swap.c						\
				)								\
				$(addprefix src/utils/,			\
					fill_out.c					\
					free_list.c					\
					ft_isdigit.c				\
					ft_lstadd_back.c			\
					ft_lstadd_front.c			\
					ft_lstnew.c					\
					ft_outadd_back.c			\
					ft_outnew.c					\
					print_list.c				\
					print_out.c					\
					ft_strlen.c					\
					is_sorted.c					\
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
