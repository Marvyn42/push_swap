#include "push_swap.h"

char	*swap_a(t_list **list)
{
	int tmp;

	// //Do nothing if there is only one or no elements.
	// if (!(*list) || !(*list)->next)
	// 	return NULL;
	// sa : swap a - swap the first 2 elements at the top of stack a.
	tmp = (*list)->next->data;
	(*list)->next->data = (*list)->data;
	(*list)->data = tmp;
	return ("sa");
}

char	*swap_b(t_list **list)
{
	int tmp;

	//Do nothing if there is only one or no elements.
	// if (!(*list) || !(*list)->next)
	// 	return ;
	// sb : swap b - swap the first 2 elements at the top of stack b.
	tmp = (*list)->next->data;
	(*list)->next->data = (*list)->data;
	(*list)->data = tmp;
	return ("sb");
}

// ss : sa and sb at the same time.
char	*swap_swap(t_list **list_a, t_list **list_b)
{
	swap_a(list_a);
	swap_b(list_b);
	return ("ss");
}
