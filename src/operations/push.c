#include "push_swap.h"

void	push_a(t_stacks *stacks)
{
	t_list *tmp;

	//Do nothing if b is empty.
	if (!stacks->b)
		return ;
	// pa : push a - take the first element at the top of b and put it at the top of a.
	tmp = stacks->b->next;
	ft_lstadd_front(&stacks->a, stacks->b);
	stacks->b = tmp;
}

void	push_b(t_stacks *stacks)
{
	t_list *tmp;

	//Do nothing if a is empty.
	if (!stacks->a)
		return ;
	// pb : push b - take the first element at the top of a and put it at the top of b.
	tmp = stacks->a->next;
	ft_lstadd_front(&stacks->b, stacks->a);
	stacks->a = tmp;
}
