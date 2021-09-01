#include "push_swap.h"

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
