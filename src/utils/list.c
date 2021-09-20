/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:14:39 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/21 00:14:39 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stacks *stacks, t_output **out)
{
	void	*tmp;

	while (stacks->a)
	{
		tmp = stacks->a->next;
		free(stacks->a);
		stacks->a = tmp;
	}
	while (stacks->b)
	{
		tmp = stacks->b->next;
		free(stacks->b);
		stacks->b = tmp;
	}
	while ((*out))
	{
		tmp = (*out)->next;
		free((*out));
		(*out) = tmp;
	}
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (!alst[0])
	{
		alst[0] = new;
		return ;
	}
	lst = alst[0];
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = alst[0];
	alst[0] = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(*ptr));
	if (!ptr)
		return (0);
	ptr->data = content;
	ptr->next = NULL;
	return (ptr);
}
