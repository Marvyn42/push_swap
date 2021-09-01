#include "push_swap.h"

// ra : rotate a - shift up all elements of stack a by 1.
// TODO: The first element becomes the last one.
char	*rotate_a(t_list **list)
{
	t_list *tmp;
	t_list *tmp2;
	
	// if ((*list) && (*list)->next)
	// {
		tmp = (*list);
		while (tmp->next->next)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp2->next = (*list);
		tmp->next = NULL;
		(*list) = tmp2;
	// }
	return ("ra");
}

// rb : rotate b - shift up all elements of stack b by 1.
// TODO: The first element becomes the last one.
char	*rotate_b(t_list **list)
{
	rotate_a(list);
	return ("rb");
}

// rr : ra and rb at the same time.
char	*rotate_rotate(t_stacks *stacks)
{
	rotate_a(&(stacks->a));
	rotate_b(&(stacks->b));
	return ("rr");
}
