/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:36:25 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/21 00:07:46 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opti_rra(t_output **begin)
{
	int			ra_count;
	int			rra_count;
	t_output	*ptr;

	ptr = (*begin)->next;
	ra_count = 0;
	rra_count = 0;
	while (ptr->arg[0] == 'r' && ptr->arg[1] == 'r' && ptr->arg[2] == 'b')
	{
		rra_count++;
		ptr = ptr->next;
	}
	while (ptr->arg[0] == 'r' && ptr->arg[1] == 'b')
	{
		ra_count++;
		ptr = ptr->next;
	}
	if (!ra_count)
		return ;
	ptr = (*begin)->next;
	if (rra_count >= ra_count)
		first_greather(rra_count, ra_count, &ptr, begin);
	else
		second_greather(rra_count, ra_count, &ptr);
	(*begin)->next = ptr;
}
