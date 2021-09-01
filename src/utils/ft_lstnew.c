#include "push_swap.h"

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
