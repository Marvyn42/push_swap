#include "push_swap.h"

char	is_sorted(t_list *list)
{
	while (list->next)
	{
		if (list->data > list->next->data)
			return (0);
		list = list->next;
	}
	return (1);
}

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
				radix_sort(&stacks, &out);
			print_list(stacks);
			print_out(out);
		}
		free_list(&stacks, &out);
	}
	return (0);
}

// TODO: Revoir le tri de 5 = condition pour ne pas faire d'étape pour rien ?
// TODO: Faire un tri pour une liste de 4 ?
// TODO: Opti la sortie OUTPUT (RA suivi de RB = RR)

// TODO: Faire un GC pour tout free par la suite ??? Nécessaire ?
// TODO: retirer fonction inutile
