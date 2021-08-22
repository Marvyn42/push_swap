/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:14:20 by mamaquig          #+#    #+#             */
/*   Updated: 2021/08/19 16:30:08 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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
**	Utils.c
*/
int				ft_isdigit(int c);
void			*ft_calloc(size_t count, size_t size);
void			print_list(t_list *a);
t_list			*ft_lstnew(int content);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			free_list(t_stacks *stacks);

#endif
