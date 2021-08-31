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

void	print_list(t_stacks stacks)
{
	int i;
	// int j;
	int tt;
	t_list *tmp;

	i = 0;
	// j = 0;
	tt = 0;
	tmp = stacks.a;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = stacks.b;
	while (tmp)
	{
		tmp = tmp->next;
		tt++;
	}
	tt = (i < tt) ? tt : i;
	printf("List A\tList B\n");
	while (tt != 0)
	{
		if (!stacks.a)
			printf("\t");
		else
			printf("%d\t", stacks.a->data);
		if (!stacks.b)
			printf("\n");
		else
			printf("%d\n", stacks.b->data);
		if (stacks.a)
			stacks.a = stacks.a->next;
		if (stacks.b)
			stacks.b = stacks.b->next;
		tt--;
	}
	printf("\n\n");
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

void	free_list(t_stacks *stacks, t_list *out)
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
	while (out)
	{
		tmp = out->next;
		free(out);
		out = tmp;
	}
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = alst[0];
	alst[0] = new;
}
