/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_rb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:36:23 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/21 00:09:07 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opti_rb(t_output **begin)
{
	int			rb_count;
	int			rrb_count;
	t_output	*ptr;

	ptr = (*begin)->next;
	rb_count = 0;
	rrb_count = 0;
	while (ptr->arg[0] == 'r' && ptr->arg[1] == 'b')
	{
		rb_count++;
		ptr = ptr->next;
	}
	while (ptr->arg[0] == 'r' && ptr->arg[1] == 'r' && ptr->arg[2] == 'b')
	{
		rrb_count++;
		ptr = ptr->next;
	}
	if (!rrb_count)
		return ;
	ptr = (*begin)->next;
	if (rb_count >= rrb_count)
		first_greather(rb_count, rrb_count, &ptr, begin);
	else
		second_greather(rb_count, rrb_count, &ptr);
	(*begin)->next = ptr;
}
