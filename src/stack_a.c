/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:32:57 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/21 18:32:17 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	skip_step(t_stacks *stacks, t_output **out)
{
	while (stacks->a && stacks->a->flag == 'P')
		fill_out(push_b(stacks), out);
	stacks->b->flag = 'S';
}

void	sort_a(t_stacks *stacks, t_output **out)
{
	int	pivot;
	int	count;
	int	alone;

	count = 0;
	alone = 1;
	pivot = set_pivot(&(stacks->a));
	if (!is_alone(stacks->a))
		alone = 0;
	if (stacks->a->flag == 'P')
		return (skip_step(stacks, out));
	while (stacks->a->flag != 'P')
	{
		if (stacks->a->data > pivot)
		{
			fill_out(rotate_a(&(stacks->a)), out);
			count++;
		}
		else
			fill_out(push_b(stacks), out);
	}
	if (!alone)
		reset_a(stacks, out, count);
}

char	a_is_sorted(t_stacks *stacks, t_output **out)
{
	if (is_ascendant(stacks->a) && !stacks->b)
		return (1);
	if (is_ascendant(stacks->a) && is_descendant(stacks->b))
	{
		while (stacks->b)
			fill_out(push_a(stacks), out);
		return (1);
	}
	return (0);
}

void	reset_a(t_stacks *stacks, t_output **out, int count)
{
	if (count)
	{
		fill_out(push_b(stacks), out);
		while (count)
		{
			fill_out(reverse_rotate_a(&(stacks->a)), out);
			count--;
		}
		fill_out(push_a(stacks), out);
	}
}
