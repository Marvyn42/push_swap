#include "push_swap.h"

char	*push_a(t_stacks *stacks)
{
	t_list *tmp;

	if (!stacks->b)
		return NULL;
	tmp = stacks->b->next;
	ft_lstadd_front(&stacks->a, stacks->b);
	stacks->b = tmp;
	return ("pa");
}

char	*push_b(t_stacks *stacks)
{
	t_list *tmp;

	if (!stacks->a)
		return NULL;
	tmp = stacks->a->next;
	ft_lstadd_front(&stacks->b, stacks->a);
	stacks->a = tmp;
	return ("pb");
}
