/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:36:20 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/21 00:05:50 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opti_ra(t_output **begin)
{
	int			ra_count;
	int			rra_count;
	t_output	*ptr;

	ptr = (*begin)->next;
	ra_count = 0;
	rra_count = 0;
	while (ptr->arg[0] == 'r' && ptr->arg[1] == 'a')
	{
		ra_count++;
		ptr = ptr->next;
	}
	while (ptr->arg[0] == 'r' && ptr->arg[1] == 'r' && ptr->arg[2] == 'a')
	{
		rra_count++;
		ptr = ptr->next;
	}
	if (!rra_count)
		return ;
	ptr = (*begin)->next;
	if (ra_count >= rra_count)
		first_greather(ra_count, rra_count, &ptr, begin);
	else
		second_greather(ra_count, rra_count, &ptr);
	(*begin)->next = ptr;
}
