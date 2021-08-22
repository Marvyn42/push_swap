#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;

	stacks.a = NULL;
	stacks.b = NULL;
	if (ac > 1)
	{
		if (!check_parse(av, &(stacks.a)))
			write(1, "Error\n", 6);
		else
			print_list(stacks.a);
		free_list(&stacks);
	}
	return (0);
}

// TODO: Faire toutes les petites fonctions.
// TODO: Faire un GC pour tout free par la suite.
// TODO: Malloc la list stacks_b, taille fixe ou dynamique ?
// TODO:
// TODO:
