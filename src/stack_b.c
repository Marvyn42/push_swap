#include "push_swap.h"

void	sort_b(t_stacks *stacks, t_output **out)
{
	int pivot;
	int count;

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
	// fill_out(push_a(stacks), out);
	//remettre en état B aussi, mais quand ???
}

char	b_is_sorted(t_list **list)
{
	//b est vide ou son last elem est flag "S"
	if (!(*list) || (*list)->flag == 'S')
		return (1);
	//si 1 seul elem alors il est sorted
	if (!(*list)->next || (*list)->next->flag == 'S' || is_descendant(*list))
	{
		(*list)->flag = 'S';
		return (1);
	}
	return (0);
}

void	reset_b(t_stacks *stacks, t_output **out, int count)
{
	if(count)
	{
		// printf("count = %d\n", count);
		//push le pivot (dans A)
		fill_out(push_a(stacks), out);
		//rrb autant de fois que rb
		while (count)
		{
			fill_out(reverse_rotate_b(&(stacks->b)), out);
			count--;
		}
		// remettre le pivot dans sa liste
		// fill_out(push_b(stacks), out);
		// printf("nouvelle liste après la remise en état:\n");
		// print_list(*stacks);
		// printf("---------------------------------------\n");
	}
}
