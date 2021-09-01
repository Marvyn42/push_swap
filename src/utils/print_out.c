#include "push_swap.h"

void	print_out(t_output *list)
{
	while (list)
	{
		printf("%s\n", list->arg);
		list = list->next;
	}
}
