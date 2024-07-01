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

int has_duplicate(t_stack *stack)
{
    t_stack *current;
	t_stack	*runner;

    current = stack;
    while (current && current->next)
	{
        runner = current->next;
        while (runner)
		{
            if (current->value == runner->value)
                return (EXIT_FAILURE);
            runner = runner->next;
        }
        current = current->next;
    }
    return (EXIT_SUCCESS);
}

void	init_args(char **args, t_stack **stack_a)
{
	int	i;
	int	j;
	int	value;
	t_stack *new;
	t_stack *last;

	*stack_a = NULL;
	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit((int)args[i][j]) && args[i][j] != '-')
				ft_error(stack_a, stack_a);
			j++;
		}
		value = ft_atoi(args[i]);
		new = new_node(value, i);
		if (!*stack_a)
			*stack_a = new;
		else
			last->next = new;
		last = new;
		i++;
	}
    if (has_duplicate(*stack_a))
	{
        ft_error(stack_a, stack_a);
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
        ft_error(&stack_a, &stack_b);
	else if (argc == 2)
	{
        args = ft_split(argv[1], ' ');
        if (!args[0])
		{
            free(args);
            ft_error(&stack_a, &stack_b);
        }
    }
	else
	{
        args = (char **)malloc(sizeof(char *) * argc);
        if (!args)
            ft_error(&stack_a, &stack_b);
        i = 1;
        while (i < argc)
		{
            if (argv[i][0] == '\0')
			{
                free(args);
                ft_error(&stack_a, &stack_b);
            }
            args[i - 1] = argv[i];
            i++;
        }
        args[argc - 1] = NULL;
    }
	init_args(args, &stack_a);
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (EXIT_SUCCESS);
}