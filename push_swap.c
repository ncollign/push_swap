

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

void	init_args(char **args, t_stack **stack_a)
{
	int				i;

	i = 0;	
	while (args[i])
	{
		if (ft_strisnumber(args[i]))
		{
			stack_a->value = ft_atoi(args[i]);
			stack_a->index = i;
		}
		else
		{
			ft_printf("Message d'erreur"); // Si ce n'est pas un nombre
			exit (EXIT_FAILED);
		}
	}
	free(args);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{

}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**args;
	int		i;

	if (argc <= 1)
	{
		ft_printf("Message d'erreur");
		exit (EXIT_FAILED); // Pas d'argument
	}
	else if (argc == 2)
		args = ft_split(argv[1], ' '); // Arguments sous forme de chaîne -> séparer en utilisant les espaces
	else
	{
		i = 1;
		while (i <= argc)
		{
			args[i - 1] = argv[i]; // Récupérer tous les arguments
		}
	}
	init_args(args, stack_a);
	sort(stack_a, stack_b);
	
	

}
