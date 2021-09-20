/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:01:06 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/21 00:01:06 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opti_pb(t_output **begin)
{
	int			pb_count;
	int			pa_count;
	t_output	*ptr;

	ptr = (*begin)->next;
	pb_count = 0;
	pa_count = 0;
	while (ptr && ptr->arg[0] == 'p' && ptr->arg[1] == 'b')
	{
		pb_count++;
		ptr = ptr->next;
	}
	while (ptr && ptr->arg[0] == 'p' && ptr->arg[1] == 'a')
	{
		pa_count++;
		ptr = ptr->next;
	}
	if (!pa_count)
		return ;
	ptr = (*begin)->next;
	if (pb_count >= pa_count)
		first_greather(pb_count, pa_count, &ptr, begin);
	else
		second_greather(pb_count, pa_count, &ptr);
	(*begin)->next = ptr;
}
