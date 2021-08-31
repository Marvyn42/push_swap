#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;
	t_output	out;

	stacks.a = NULL;
	stacks.b = NULL;
	if (ac > 1)
	{
		if (!check_parse(av, &stacks.a))
			write(1, "Error\n", 6);
		else
		{
			if (ac <= 6)
				small_size(&stacks, (ac - 1), &out);
			else
			{
				//
			}
			print_list(stacks);
			free_list(&stacks, &out);
		}
	}
	return (0);
}

// TODO: Faire un GC pour tout free par la suite ??? Nécessaire ?
// TODO: retirer fonction inutile

			// print_list(stacks);
			// push_b(&stacks);
			// push_b(&stacks);
			// push_b(&stacks);
			// print_list(stacks);
			// rotate_rotate(&stacks);
			// rotate_b(&(stacks.b));
			// print_list(stacks);
			// reverse_rotate_a(&(stacks.a));
			// print_list(stacks);
			// reverse_rotate_reverse(&stacks);
			// print_list(stacks);
