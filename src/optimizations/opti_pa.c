/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:01:44 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/21 00:03:33 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opti_pa(t_output **begin)
{
	int			pa_count;
	int			pb_count;
	t_output	*ptr;

	ptr = (*begin)->next;
	pa_count = 0;
	pb_count = 0;
	while (ptr && ptr->arg[0] == 'p' && ptr->arg[1] == 'a')
	{
		pa_count++;
		ptr = ptr->next;
	}
	while (ptr && ptr->arg[0] == 'p' && ptr->arg[1] == 'b')
	{
		pb_count++;
		ptr = ptr->next;
	}
	if (!pb_count)
		return ;
	ptr = (*begin)->next;
	if (pa_count >= pb_count)
		first_greather(pa_count, pb_count, &ptr, begin);
	else
		second_greather(pa_count, pb_count, &ptr);
	(*begin)->next = ptr;
}
