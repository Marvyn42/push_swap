#include "push_swap.h"

t_output	*ft_outnew(void *content)
{
	t_output	*ptr;

	ptr = malloc((sizeof(content) + sizeof(t_output *)));
	if (!ptr)
		return (0);
	ptr->arg = content;
	ptr->next = 0;
	return (ptr);
}
