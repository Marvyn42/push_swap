/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:14:42 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/21 00:14:42 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_out(char *arg, t_output **out)
{
	if (!(*out))
		(*out) = ft_outnew(arg);
	else
		ft_outadd_back(out, ft_outnew(arg));
}

void	ft_outadd_back(t_output **alst, t_output *new)
{
	t_output	*lst;

	if (!alst[0])
	{
		alst[0] = new;
		return ;
	}
	lst = alst[0];
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}

t_output	*ft_outnew(void *content)
{
	t_output	*ptr;

	ptr = malloc((sizeof(content) + sizeof(t_output *)));
	if (!ptr)
		return (0);
	ptr->arg = content;
	ptr->next = 0;
	return (ptr);
}

void	print_out(t_output *list)
{
	while (list)
	{
		write(1, list->arg, ft_strlen(list->arg));
		write(1, "\n", 1);
		list = list->next;
	}
}
