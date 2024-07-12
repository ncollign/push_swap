/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:44:11 by ncollign          #+#    #+#             */
/*   Updated: 2024/07/09 11:44:14 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_stack *stack)
/*
	This function verify if there are no duplicates in a stack
	Returns 0 if OK
	Returns 1 if NOK
*/
{
	t_stack	*current;
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
/*
	This function initialize arguments and create nodes with values inside
*/
{
	t_stack	*new;
	t_stack	*last;
	int		i;
	int		value;

	*stack_a = NULL;
	last = NULL;
	i = 0;
	while (args[i])
	{
		if (validate_argument(args[i]))
			handle_argument_error(args, stack_a);
		value = ft_atoi(args[i]);
		if (ft_conversion_ok(args[i], value))
			handle_argument_error(args, stack_a);
		new = new_node(value, i);
		if (!new)
			handle_argument_error(args, stack_a);
		if (!*stack_a)
			*stack_a = new;
		else
			last->next = new;
		last = new;
		i++;
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
/*
	Function to initialize the sort
*/
{
	if (!is_sort(*stack_a))
	{
		if (get_stack_size(*stack_a) <= 3)
			tiny_sort(stack_a);
		else
			big_sort(stack_a, stack_b);
	}
	free_stack(stack_a);
	free_stack(stack_b);
}

static char	**multiple_arguments(char **argv, int argc,
t_stack **stack_a, t_stack **stack_b)
/*
	This function verifies all the arguments and split it into a variable args
	Returns args
*/
{
	char	**args;
	int		i;

	args = malloc(sizeof(char *) * (argc + 1));
	if (!args)
		ft_error(stack_a, stack_b);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
		{
			free_args(args);
			ft_error(stack_a, stack_b);
		}
		args[i - 1] = ft_strdup(argv[i]);
		i++;
	}
	args[i - 1] = NULL;
	return (args);
}

int	main(int argc, char **argv)
/*
	Main function
*/
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		ft_error(&stack_a, &stack_b);
	else if (argc == 2)
	{
		if (argv[1][0] == '\0' || argv[1][0] == ' ')
			ft_error(&stack_a, &stack_b);
		args = ft_split(argv[1], ' ');
		if (!args)
			ft_error(&stack_a, &stack_b);
	}
	else
		args = multiple_arguments(argv, argc, &stack_a, &stack_b);
	init_args(args, &stack_a);
	free_args(args);
	if (has_duplicate(stack_a))
		ft_error(&stack_a, &stack_a);
	sort(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
