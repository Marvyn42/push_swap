#include "push_swap.h"

void	sorted_part(t_stacks *stacks, t_output **out)
{
	t_list	*tmp;
	int		index ;

	tmp = stacks->a->next;
	index = 1;
	while (tmp && tmp->flag != 'P')
	{
		if (tmp->data > tmp->next->data)
			return ;
		index++;
		tmp = tmp->next;
	}
	index++;
	// print_list(*stacks);
	while (index != 0)
	{
		fill_out(push_b(stacks), out);
		index--;
	}
	stacks->b->flag = 'S';
	// print_list(*stacks);
}

//opti les appels de fct pour faire 2 cas dans une seule. Passer de 6 fct à 3 et tout avoir dans le fichier
void	output_cleaning(t_output **out)
{
	t_output	*tmp;

	tmp = (*out);
	while (tmp->next)
	{
		while (tmp->next->arg[0] == 'r' && tmp->next->arg[1] == 'b')
			//apl_fct(tmp, out);
		while (tmp->next->arg[0] == 'r' && tmp->next->arg[1] == 'r' && tmp->next->arg[2] == 'b')
			//apl_fct(tmp, out);
		while (tmp->next->arg[0] == 'r' && tmp->next->arg[1] == 'a')
			//apl_fct(tmp, out);
		while (tmp->next->arg[0] == 'r' && tmp->next->arg[1] == 'r' && tmp->next->arg[2] == 'a')
			//apl_fct(tmp, out);
		while (tmp->next->arg[0] == 'p' && tmp->next->arg[1] == 'a')
			//apl_fct(tmp, out);
		while (tmp->next->arg[0] == 'p' && tmp->next->arg[1] == 'b')
			//apl_fct(tmp, out);
		tmp = tmp->next;
	}
}
