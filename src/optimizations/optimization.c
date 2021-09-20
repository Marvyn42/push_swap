/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:36:29 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/21 00:05:44 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (index != 0)
	{
		fill_out(push_b(stacks), out);
		index--;
	}
	stacks->b->flag = 'S';
}

void	output_cleaning(t_output **out)
{
	t_output	*tmp;

	tmp = (*out);
	while (tmp->next)
	{
		if (tmp->next->arg[0] == 'r' && tmp->next->arg[1] == 'b')
			opti_rb(&tmp);
		else if (tmp->next->arg[0] == 'r' && tmp->next->arg[1] == 'r'
			&& tmp->next->arg[2] == 'b')
			opti_rrb(&tmp);
		else if (tmp->next->arg[0] == 'r' && tmp->next->arg[1] == 'a')
			opti_ra(&tmp);
		else if (tmp->next->arg[0] == 'r' && tmp->next->arg[1] == 'r'
			&& tmp->next->arg[2] == 'a')
			opti_rra(&tmp);
		else if (tmp->next->arg[0] == 'p' && tmp->next->arg[1] == 'a')
			opti_pa(&tmp);
		else if (tmp->next->arg[0] == 'p' && tmp->next->arg[1] == 'b')
			opti_pb(&tmp);
		tmp = tmp->next;
	}
}

void	second_greather(int smaller, int greather, t_output **ptr)
{
	t_output	*tmp;

	greather = smaller;
	while (smaller)
	{
		tmp = (*ptr);
		(*ptr) = (*ptr)->next;
		free(tmp);
		smaller--;
	}
	while (greather)
	{
		tmp = (*ptr);
		(*ptr) = (*ptr)->next;
		free(tmp);
		greather--;
	}
}

void	first_greather(int greather, int smaller, t_output **ptr,
		t_output **begin)
{
	t_output	*tmp;

	while (greather - smaller != 0)
	{
		(*ptr) = (*ptr)->next;
		greather--;
		(*begin) = (*begin)->next;
	}
	while (greather)
	{
		tmp = (*ptr);
		(*ptr) = (*ptr)->next;
		free(tmp);
		greather--;
	}
	while (smaller)
	{
		tmp = (*ptr);
		(*ptr) = (*ptr)->next;
		free(tmp);
		smaller--;
	}
}
