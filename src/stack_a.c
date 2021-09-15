#include "push_swap.h"

void	skip_step(t_stacks *stacks, t_output **out)
{
	while (stacks->a && stacks->a->flag == 'P')
		fill_out(push_b(stacks), out);
	stacks->b->flag = 'S';
}

void	sort_a(t_stacks *stacks, t_output **out)
{
	int pivot;
	int count;
	int alone;

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
		// print_list(*stacks);
	}
	if (!alone)
		reset_a(stacks, out, count);
}

char	a_is_sorted(t_stacks *stacks, t_output **out)
{
	//a est triée (ascendant) et b est vide
	if (is_ascendant(stacks->a) && !stacks->b)
		return (1);
	//a est triée (ascendant) et b triée (descendant)
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
	if(count)
	{
		printf("count = %d\n", count);
		//push le pivot (dans B)
		fill_out(push_b(stacks), out);
		//rra autant de fois que ra
		while (count)
		{
			fill_out(reverse_rotate_a(&(stacks->a)), out);
			count--;
		}
		// remettre le pivot dans sa liste
		fill_out(push_a(stacks), out);
		// printf("nouvelle liste après la remise en état:\n");
		// print_list(*stacks);
		// printf("---------------------------------------\n");
	}
}
