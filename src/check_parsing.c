/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:26:19 by mamaquig          #+#    #+#             */
/*   Updated: 2021/09/21 00:26:29 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_flags(t_list **list)
{
	t_list	*tmp;

	tmp = (*list);
	while (tmp)
	{
		tmp->flag = 'R';
		tmp = tmp->next;
	}
}

char	check_multiple(t_list *list)
{
	t_list	*next;

	next = list->next;
	while (list)
	{
		next = list->next;
		while (next)
		{
			if (list->data == next->data)
				return (0);
			next = next->next;
		}
		list = list->next;
	}
	return (1);
}

char	check_parse(char **args, t_list **list)
{
	int		i;
	int		res;
	int		neg;
	t_list	*tmp;

	i = 1;
	neg = 1;
	while (args[i])
	{
		if (args[i][0] == '-')
			neg = -1;
		res = check_args(args[i]);
		if (res == -1)
			return (0);
		tmp = ft_lstnew(res * neg);
		if (!tmp)
			return (0);
		ft_lstadd_back(list, tmp);
		i++;
		neg = 1;
	}
	if (!check_multiple(*list))
		return (0);
	init_flags(list);
	return (1);
}

unsigned int	check_args(const char *str)
{
	unsigned int		res;
	unsigned char		i;
	unsigned char		neg;

	neg = 0;
	i = 0;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	res = 0;
	while (str[i])
	{
		if (i >= (10 + neg) || !ft_isdigit(str[i]))
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > (unsigned int)__INT_MAX__ + neg)
		return (-1);
	return (res);
}
