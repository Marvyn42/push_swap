/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:34:25 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/21 17:42:32 by mamaquig         ###   ########.fr       */
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
			{
				quick_sort(&stacks, &out);
				output_cleaning(&out);
			}
			print_out(out);
		}
		free_list(&stacks, &out);
	}
	return (0);
}
