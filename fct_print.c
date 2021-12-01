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
			printf("%d %c\t", stacks.a->data, stacks.a->flag);
		if (!stacks.b)
			printf("\n");
		else
			printf("%d %c\n", stacks.b->data, stacks.b->flag);
		if (stacks.a)
			stacks.a = stacks.a->next;
		if (stacks.b)
			stacks.b = stacks.b->next;
		tt--;
	}
	printf("\n\n");
}
