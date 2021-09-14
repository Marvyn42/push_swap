#include "push_swap.h"

char	is_sorted(t_list *list)
{
	while (list->next)
	{
		if (list->data > list->next->data)
			return (0);
		list = list->next;
	}
	return (1);
}
