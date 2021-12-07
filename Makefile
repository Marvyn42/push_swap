# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 22:08:43 by mamaquig          #+#    #+#              #
#    Updated: 2021/12/06 13:23:48 by mamaquig         ###   ########.fr        #
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
					list.c						\
					outlist.c					\
					utils.c						\
				)								\
				$(addprefix src/optimizations/,	\
					optimization.c				\
					opti_rb.c					\
					opti_ra.c					\
					opti_rrb.c					\
					opti_rra.c					\
					opti_pa.c					\
					opti_pb.c					\
				)
OBJ			=	$(SRC:.c=.o)
CC			=	gcc
HEADER		=	-Iheader
CFLAGS		=	-Wall -Wextra -Werror

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
