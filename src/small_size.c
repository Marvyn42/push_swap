#include "push_swap.h"

void	small_size(t_stacks *stacks, int size, t_output **out)
{
	if (size == 2)
		size_two(&(stacks->a), out);
	else if (size == 3)
		size_three(&(stacks->a), out);
	else
		size_ff(stacks, out, size);
}

void	size_two(t_list **list, t_output **out)
{
	if ((*list)->data > (*list)->next->data)
		fill_out(swap_a(list), out);
}

void	size_three(t_list **list, t_output **out)
{
	if ((*list)->next->data < (*list)->data && (*list)->data >
		(*list)->next->next->data)
		fill_out(reverse_rotate_a(list), out);
	if ((*list)->data > (*list)->next->data)
		fill_out(swap_a(list), out);
	if ((*list)->next->data > (*list)->next->next->data)
	{
		fill_out(rotate_a(list), out);
		if ((*list)->data > (*list)->next->data)
			fill_out(swap_a(list), out);
	}
}

void	size_ff(t_stacks *stacks, t_output **out, int size)
{
	fill_out(push_b(stacks), out);
	fill_out(push_b(stacks), out);
	if (size == 5)
		size_three(&(stacks->a), out);
	else
		size_two(&(stacks->a), out);
	fill_out(push_b(stacks), out);
	if (stacks->b->next->data > stacks->b->data && stacks->b->data <
		stacks->b->next->next->data)
		fill_out(reverse_rotate_a(&(stacks->b)), out);
	if (stacks->b->data < stacks->b->next->data)
		fill_out(swap_a(&(stacks->b)), out);
	if (stacks->b->next->data < stacks->b->next->next->data)
	{
		fill_out(rotate_a(&(stacks->b)), out);
		if (stacks->b->data < stacks->b->next->data)
			fill_out(swap_a(&(stacks->b)), out);
	}
	fill_out(push_a(stacks), out);
	if (size == 5)
		size_three(&(stacks->a), out);
	fill_out(push_a(stacks), out);
	if (size == 4)
		size_three(&(stacks->a), out);
	fill_out(push_a(stacks), out);
}
