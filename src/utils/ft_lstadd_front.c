#include "push_swap.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = alst[0];
	alst[0] = new;
}
