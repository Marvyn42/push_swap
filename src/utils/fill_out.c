#include "push_swap.h"

void	fill_out(char *arg, t_output **out)
{
	if (!(*out))
		(*out) = ft_outnew(arg);
	else
		ft_outadd_back(out, ft_outnew(arg));
}
