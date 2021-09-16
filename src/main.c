#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;
	t_output	*out;

	stacks.a = NULL;
	stacks.b = NULL;
	out = NULL;
	if (ac > 1)
	{
		if (!check_parse(av, &stacks.a))
			write(1, "Error\n", 6);
		else
		{
			if (!is_sorted(stacks.a) && ac <= 6)
				small_size(&stacks, (ac - 1), &out);
			else if (!is_sorted(stacks.a) && ac > 6)
				quick_sort(&stacks, &out);
			// print_list(stacks);
			print_out(out);
			// output_cleaning(&out);
		}
		free_list(&stacks, &out);
	}
	return (0);
}

// TODO: Opti la sortie OUTPUT ? (RA suivi de RB = RR)
// integrer un tri dinsersion pour les petites portions

// Faire la technique d'antoine ou tu met ta liste triee a la fin de A au lieu de sur B
// Pivot médiane

//TODO: ranger proprement dans utils
