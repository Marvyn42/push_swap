#include "push_swap.h"

char	is_descendant(t_list *list)
{
	int tmp;

	if (!list->next)
		return (1);
	tmp = list->data;
	list = list->next;
	while (list)
	{
		if (tmp < list->data)
			return (0);
		tmp = list->data;
		list = list->next;
	}
	return (1);
}

char	is_ascendant(t_list *list)
{
	int tmp;

	if (!list || !list->next)
		return (1);
	tmp = list->data;
	list = list->next;
	while (list)
	{
		if (tmp > list->data)
			return (0);
		tmp = list->data;
		list = list->next;
	}
	return (1);
}

int		set_pivot(t_list **list)
{
	t_list *tmp;
	t_list *prev;
	int		pivot;

	tmp = (*list);
	prev = tmp;
	while (tmp->next)
	{
		if (tmp->flag == 'P' || tmp->flag == 'S')
		{
			prev->flag = 'P';
			return (pivot = prev->data);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->flag = 'P';
	return (pivot = tmp->data);
}

char	is_alone(t_list *list)
{
	t_list *tmp;
	int count;

	tmp = list;
	count = 0;
	while (tmp)
	{
		if (tmp->flag == 'P')
			count++;
		tmp = tmp->next;
	}
	if (count > 1)
		return (0);
	return (1);
}



void	quick_sort(t_stacks *stacks, t_output **out)
{
	// print_list(*stacks);
	while (!a_is_sorted(stacks, out))
	{
		sort_a(stacks, out);
		// print_list(*stacks);
		while (!b_is_sorted(&(stacks->b)))
			sort_b(stacks, out);
		// print_list(*stacks);
	}
}
