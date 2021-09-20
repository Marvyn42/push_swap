/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:35:43 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/20 21:35:43 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swap_a(t_list **list)
{
	int	tmp;

	tmp = (*list)->next->data;
	(*list)->next->data = (*list)->data;
	(*list)->data = tmp;
	return ("sa");
}

char	*swap_b(t_list **list)
{
	int	tmp;

	tmp = (*list)->next->data;
	(*list)->next->data = (*list)->data;
	(*list)->data = tmp;
	return ("sb");
}

char	*swap_swap(t_list **list_a, t_list **list_b)
{
	swap_a(list_a);
	swap_b(list_b);
	return ("ss");
}
