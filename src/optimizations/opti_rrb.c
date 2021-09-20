/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_rrb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:36:27 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/21 00:08:23 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opti_rrb(t_output **begin)
{
	int			rb_count;
	int			rrb_count;
	t_output	*ptr;

	ptr = (*begin)->next;
	rb_count = 0;
	rrb_count = 0;
	while (ptr->arg[0] == 'r' && ptr->arg[1] == 'r' && ptr->arg[2] == 'b')
	{
		rrb_count++;
		ptr = ptr->next;
	}
	while (ptr->arg[0] == 'r' && ptr->arg[1] == 'b')
	{
		rb_count++;
		ptr = ptr->next;
	}
	if (!rb_count)
		return ;
	ptr = (*begin)->next;
	if (rrb_count >= rb_count)
		first_greather(rrb_count, rb_count, &ptr, begin);
	else
		second_greather(rrb_count, rb_count, &ptr);
	(*begin)->next = ptr;
}
