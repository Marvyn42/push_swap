#include "push_swap.h"

void	small_size(t_stacks *stacks, int size, t_list *out)
{
	if (size == 2)
		size_two(stacks, out);
	else if (size == 3)
		size_three(stacks, out);
	else if (size == 4)
		size_four(stacks, out);
	else if (size == 5)
		size_five(stacks, out);
}

void	size_two(t_stacks *stacks, t_list *out)
{
	if (stacks->a->data > stacks->a->next->data)
	{
		swap_a(&(stacks->a));
	}
}

void	size_three(t_stacks *stacks, t_list *out)
{
	//
}

void	size_four(t_stacks *stacks, t_list *out)
{
	//
}

void	size_five(t_stacks *stacks, t_list *out)
{
	//
}
