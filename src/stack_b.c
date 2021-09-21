/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:33:31 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/21 18:49:22 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_stacks *stacks, t_output **out)
{
	int	pivot;
	int	count;

	count = 0;
	pivot = set_pivot(&(stacks->b));
	while (stacks->b->flag != 'P' && stacks->b->flag != 'S')
	{
		if (stacks->b->data < pivot)
		{
			fill_out(rotate_b(&(stacks->b)), out);
			count++;
		}
		else
			fill_out(push_a(stacks), out);
	}
	if (is_descendant(stacks->b))
	{
		stacks->b->flag = 'S';
		return ;
	}
	else
		reset_b(stacks, out, count);
}

char	b_is_sorted(t_list **list)
{
	if (!(*list) || (*list)->flag == 'S')
		return (1);
	if (!(*list)->next || (*list)->next->flag == 'S' || is_descendant(*list))
	{
		(*list)->flag = 'S';
		return (1);
	}
	return (0);
}

void	reset_b(t_stacks *stacks, t_output **out, int count)
{
	if (count)
	{
		fill_out(push_a(stacks), out);
		while (count)
		{
			fill_out(reverse_rotate_b(&(stacks->b)), out);
			count--;
		}
	}
}
