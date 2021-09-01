#include "push_swap.h"

void	free_list(t_stacks *stacks, t_output **out)
{
	void	*tmp;

	while (stacks->a)
	{
		tmp = stacks->a->next;
		free(stacks->a);
		stacks->a = tmp;
	}
	while (stacks->b)
	{
		tmp = stacks->b->next;
		free(stacks->b);
		stacks->b = tmp;
	}
	while ((*out))
	{
		tmp = (*out)->next;
		free((*out));
		(*out) = tmp;
	}
}
