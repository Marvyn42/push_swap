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
			print_list(stacks);
			if (ac <= 6)
				small_size(&stacks, (ac - 1), &out);
			else
			{
				//
			}
			print_list(stacks);
			print_out(out);
			free_list(&stacks, &out);
		}
	}
	return (0);
}

// TODO: Faire un GC pour tout free par la suite ??? Nécessaire ?
// TODO: retirer fonction inutile
