/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:34:25 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/21 00:34:24 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			output_cleaning(&out);
			print_out(out);
		}
		free_list(&stacks, &out);
	}
	return (0);
}

// integrer un tri dinsersion pour les petites portions
// Faire la technique d'antoine ou tu met ta liste triee a la fin de A au lieu de sur B
// Pivot médiane

//TODO: Norme
//TODO: .o qui ne se suppriment pas
//TODO: retirer flag compilation dans Makefile
//TODO: suppr fct print_list
