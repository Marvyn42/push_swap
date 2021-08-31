/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:14:20 by mamaquig          #+#    #+#             */
/*   Updated: 2021/08/31 14:53:29 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_output
{
	char			*arg;
	struct s_output	*next;
}				t_output;

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}				t_list;

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}				t_stacks;

/*
**	check_parsing.c
*/
char			check_parse(char **args, t_list **list);
unsigned int	check_args(const char *str);

/*
** small_size.c
*/
void			small_size(t_stacks *stacks, int size, t_list *out);
void			size_two(t_stacks *stacks, t_list *out);
void			size_three(t_stacks *stacks, t_list *out);
void			size_four(t_stacks *stacks, t_list *out);
void			size_five(t_stacks *stacks, t_list *out);



/*
** swap.c
*/
void			swap_a(t_list **list);
void			swap_b(t_list **list);
void			swap_swap(t_list **list_a, t_list **list_b);

/*
** push.c
*/
void			push_a(t_stacks *stacks);
void			push_b(t_stacks *stacks);

/*
** rotate.c
*/
void			rotate_a(t_list **list);
void			rotate_b(t_list **list);
void			rotate_rotate(t_stacks *stacks);

/*
** reverse.c
*/
void			reverse_rotate_a(t_list **list);
void			reverse_rotate_b(t_list **list);
void			reverse_rotate_reverse(t_stacks *stacks);

/*
**	Utils.c
*/
int				ft_isdigit(int c);
void			*ft_calloc(size_t count, size_t size);
void			print_list(t_stacks stacks);
t_list			*ft_lstnew(int content);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			free_list(t_stacks *stacks, t_list *out);
void			ft_lstadd_front(t_list **alst, t_list *new);

#endif
