/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:14:20 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/06 14:42:52 by mamaquig         ###   ########.fr       */
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
** radix_sort.c
*/
void			radix_sort(t_stacks *stacks, t_output **out);

/*
**	check_parsing.c
*/
char			check_parse(char **args, t_list **list);
unsigned int	check_args(const char *str);

/*
** small_size.c
*/
void			small_size(t_stacks *stacks, int size, t_output **out);
void			size_three(t_list **list, t_output **out);
void			three_reverse(t_stacks *stacks, t_output **out);
void			size_ff(t_stacks *stacks, t_output **out, int size);

/*
** swap.c
*/
char			*swap_a(t_list **list);
char			*swap_b(t_list **list);
char			*swap_swap(t_list **list_a, t_list **list_b);

/*
** push.c
*/
char			*push_a(t_stacks *stacks);
char			*push_b(t_stacks *stacks);

/*
** rotate.c
*/
char			*rotate_a(t_list **list);
char			*rotate_b(t_list **list);
char			*rotate_rotate(t_stacks *stacks);

/*
** reverse.c
*/
char			*reverse_rotate_a(t_list **list);
char			*reverse_rotate_b(t_list **list);
char			*reverse_rotate_reverse(t_stacks *stacks);

/*
**	Utils
*/
void			fill_out(char *arg, t_output **out);
void			free_list(t_stacks *stacks, t_output **out);
int				ft_isdigit(int c);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstadd_front(t_list **alst, t_list *new);
t_list			*ft_lstnew(int content);
void			ft_outadd_back(t_output **alst, t_output *new);
t_output		*ft_outnew(void *content);
void			print_list(t_stacks stacks);
void			print_out(t_output *list);
int				ft_strlen(char *str);

#endif
