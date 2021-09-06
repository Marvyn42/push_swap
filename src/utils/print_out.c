#include "push_swap.h"

void	print_out(t_output *list)
{
	while (list)
	{
		write(1, list->arg, ft_strlen(list->arg));
		write(1, "\n", 1);
		list = list->next;
	}
}
