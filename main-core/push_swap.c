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
		// Vérifiez si l'argument est un nombre
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		while (args[i][j])
		{
			if (!ft_isdigit((int)args[i][j]))
			{
				ft_printf("Error\nPlease enter only numbers\n"); // Si ce n'est pas un nombre
				exit (EXIT_FAILURE);
			}
			j++;
		}
		// Si l'argument est un nombre, créez un nouveau nœud et ajoutez-le à la pile
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

void print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("Value: %d, Index: %d\n", stack->value, stack->index);
		stack = stack->next;
	}
	ft_printf("------------------\n");
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	
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
		ft_printf("Error\nNo arguments\n");
		exit(EXIT_FAILURE); // Pas d'argument
	}
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' '); // Arguments sous forme de chaîne -> séparer en utilisant les espaces
	}
	else
	{
		args = (char **)malloc(sizeof(char *) * argc);
		if (!args)
		{
			ft_printf("Erreur d'allocation mémoire\n");
			exit(EXIT_FAILURE);
		}
		i = 1;
		while (i < argc)
		{
			args[i - 1] = argv[i]; // Récupérer tous les arguments
			i++;
		}
		args[argc - 1] = NULL;
	}

	init_args(args, &stack_a);
	print_stack(stack_a);
	//sort(&stack_a, &stack_b);
	ss(&stack_a, &stack_b);
	print_stack(stack_a);

	// Libération de la mémoire utilisée par les piles
	t_stack *tmp;
	while (stack_a)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
	while (stack_b)
	{
		tmp = stack_b;
		stack_b = stack_b->next;
		free(tmp);
	}

	return 0;
}
