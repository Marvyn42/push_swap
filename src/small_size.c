/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:32:40 by mamaquig          #+#    #+#             */
/*   Updated: 2021/12/06 18:11:08 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_size(t_stacks *stacks, int size, t_output **out)
{
	if (size == 2 && (stacks->a->data > stacks->a->next->data))
		fill_out(swap_a(&(stacks->a)), out);
	else if (size == 3)
		size_three(&(stacks->a), out);
	else if (size == 4 || size == 5)
		size_ff(stacks, out, size);
}

void	size_three(t_list **list, t_output **out)
{
	while (!is_ascendant((*list)))
	{
		if ((*list)->data > (*list)->next->data && ((*list)->next->next->data
				> (*list)->data && (*list)->next->next->data > (*list)->data))
			fill_out(swap_a(list), out);
		else if ((*list)->next->next->data > (*list)->next->data
			&& ((*list)->data > (*list)->next->data
				&& (*list)->data > (*list)->next->next->data))
			fill_out(rotate_a(list), out);
		else if ((*list)->data > (*list)->next->next->data
			&& ((*list)->next->data > (*list)->data
				&& (*list)->next->data > (*list)->next->next->data))
			fill_out(reverse_rotate_a(list), out);
		else if ((*list)->next->data > (*list)->next->next->data
			&& ((*list)->data > (*list)->next->data
				&& (*list)->data > (*list)->next->next->data))
			fill_out(swap_a(list), out);
		else if ((*list)->next->next->data > (*list)->data
			&& ((*list)->next->data > (*list)->data
				&& (*list)->next->data > (*list)->next->next->data))
			fill_out(swap_a(list), out);
	}
}

void	sort_stack_four(t_stacks *stacks, t_output **out)
{
	if (stacks->b->data > stacks->a->data
		&& stacks->b->data < stacks->a->next->data)
	{
		// printf("\n\tpart 1 size 4\n");
		// print_list(*stacks);
		fill_out(push_a(stacks), out);
		fill_out(swap_a(&(stacks->a)), out);
	}
	else if (stacks->b->data > stacks->a->next->data
		&& stacks->b->data < stacks->a->next->next->data)
	{
		// printf("\n\tpart 2 size 4\n");
		// print_list(*stacks);
		fill_out(reverse_rotate_a(&(stacks->a)), out);
		fill_out(push_a(stacks), out);
		fill_out(rotate_a(&(stacks->a)), out);
		fill_out(rotate_a(&(stacks->a)), out);
	}
	else if (stacks->b->data > stacks->a->next->next->data)
	{
		// printf("\n\tpart 3 size 4\n");
		// print_list(*stacks);
		fill_out(push_a(stacks), out);
		fill_out(rotate_a(&(stacks->a)), out);
	}
	else
	{
		// printf("\n\tpart 4 size 4\n");
		// print_list(*stacks);
		fill_out(push_a(stacks), out);
	}
}

void	sort_stack_five(t_stacks *stacks, t_output **out)
{
	if (stacks->b->data > stacks->a->data
		&& stacks->b->data < stacks->a->next->data)
	{
		// printf("\n\tpart 1 size 5\n");
		// print_list(*stacks);
		fill_out(push_a(stacks), out);
		fill_out(swap_a(&(stacks->a)), out);
	}
	else if (stacks->b->data > stacks->a->next->data
		&& stacks->b->data < stacks->a->next->next->data)
	{
		// printf("\n\tpart 2 size 5\n");
		// print_list(*stacks);
		fill_out(rotate_a(&(stacks->a)), out);
		fill_out(rotate_a(&(stacks->a)), out);
		fill_out(push_a(stacks), out);
		fill_out(reverse_rotate_a(&(stacks->a)), out);
		fill_out(reverse_rotate_a(&(stacks->a)), out);
	}
	else if (stacks->b->data > stacks->a->next->next->data)
	{
		// printf("\n\tpart 3 size 5\n");
		// print_list(*stacks);
		fill_out(reverse_rotate_a(&(stacks->a)), out);
		fill_out(push_a(stacks), out);
		fill_out(rotate_a(&(stacks->a)), out);
		fill_out(rotate_a(&(stacks->a)), out);
	}
	else
	{
		// printf("\n\tpart 4 size 5\n");
		// print_list(*stacks);
		fill_out(push_a(stacks), out);
	}
}

void	size_ff(t_stacks *stacks, t_output **out, int size)
{
	// print_list(*stacks);
	fill_out(push_b(stacks), out);
	if (size == 5)
		fill_out(push_b(stacks), out);
	size_three(&(stacks->a), out);
	sort_stack_four(stacks, out);
	// print_list(*stacks);
	if (size == 4)
		return ;
	if (stacks->b->data > stacks->a->next->next->next->data)
	{
		fill_out(push_a(stacks), out);
		fill_out(rotate_a(&(stacks->a)), out);
	}
	else
		sort_stack_five(stacks, out);
}
