#include "push_swap.h"

int		ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char*)malloc(size * count);
	if (!ptr)
		return (0);
	i = 0;
	while (i < size * count)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%d\n", list->data);
		list = list->next;
	}
}

t_list	*ft_lstnew(int content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(*ptr));
	if (!ptr)
		return (0);
	ptr->data = content;
	ptr->next = NULL;
	return (ptr);
}

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

void	free_list(t_stacks *stacks)
{
	void	*tmp;

	while (stacks->a)
	{
		tmp = stacks->a->next;
		free(stacks->a);
		stacks->a = tmp;
	}
	while (stacks->b)
	{
		tmp = stacks->b->next;
		free(stacks->b);
		stacks->b = tmp;
	}
}
