#include "push_swap.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

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
