/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:34:12 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/20 21:34:15 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*push_a(t_stacks *stacks)
{
	t_list	*tmp;

	if (!stacks->b)
		return (NULL);
	tmp = stacks->b->next;
	ft_lstadd_front(&stacks->a, stacks->b);
	stacks->b = tmp;
	return ("pa");
}

char	*push_b(t_stacks *stacks)
{
	t_list	*tmp;

	if (!stacks->a)
		return (NULL);
	tmp = stacks->a->next;
	ft_lstadd_front(&stacks->b, stacks->a);
	stacks->a = tmp;
	return ("pb");
}
