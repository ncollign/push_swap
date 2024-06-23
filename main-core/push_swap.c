#include "push_swap.h"

t_stack *new_node(int value, int index)
{
	t_stack *node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return NULL;
	node->value = value;
	node->index = index;
	node->next = NULL;
	return node;
}

void	init_args(char **args, t_stack **stack_a)
{
	int	i;
	int	j;
	t_stack *new;
	t_stack *last;

	*stack_a = NULL;
	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		while (args[i][j])
		{
			if (!ft_isdigit((int)args[i][j]))
			{
				ft_error(stack_a, stack_a);
				exit (EXIT_FAILURE);
			}
			j++;
		}
		new = new_node(ft_atoi(args[i]), i);
		if (!*stack_a)
		{
			*stack_a = new;
		}
		else
		{
			last = *stack_a;
			while (last->next)
				last = last->next;
			last->next = new;
		}
		i++;
	}
	free(args);
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char **args;
	int i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
	{
		ft_error(&stack_a, &stack_b);
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = (char **)malloc(sizeof(char *) * argc);
		if (!args)
		{
			ft_error(&stack_a, &stack_b);
			exit(EXIT_FAILURE);
		}
		i = 1;
		while (i < argc)
		{
			args[i - 1] = argv[i];
			i++;
		}
		args[argc - 1] = NULL;
	}
	init_args(args, &stack_a);
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_a);
	return (EXIT_SUCCESS);
}