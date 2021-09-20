/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:34:18 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/20 21:34:19 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*reverse_rotate_a(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	if ((*list) && (*list)->next)
	{
		tmp2 = (*list);
		while (tmp2->next)
		{
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
		tmp->next = NULL;
		tmp2->next = *list;
		*list = tmp2;
	}
	return ("rra");
}

char	*reverse_rotate_b(t_list **list)
{
	reverse_rotate_a(list);
	return ("rrb");
}

char	*reverse_rotate_reverse(t_stacks *stacks)
{
	reverse_rotate_a(&(stacks->a));
	reverse_rotate_a(&(stacks->b));
	return ("rrr");
}
