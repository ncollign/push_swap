#include "push_swap.h"

void	free_stack(t_stack **stack)
/*
	This functions free a stack
*/
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void ft_error(t_stack **stack_a, t_stack **stack_b)
/*
	This function prints an error message
*/
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
    write(STDERR_FILENO, "Error\n", 6);
    exit(EXIT_FAILURE);
}

int is_sort(t_stack *stack)
/*
	This functions checks if the stack is sorted
	Returns 1 if OK
	Returns 0 if NOK
*/
{
	while (stack)
	{
		if (!stack->next && stack->value == get_min(stack))
			return (1);
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int is_reverse_sort(t_stack *stack)
/*
	This functions checks if the stack is reverse sorted
	Returns 1 if OK
	Returns 0 if NOK
*/
{
	while (stack)
	{
		if (!stack->next && stack->value == get_max(stack))
			return (1);
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*last_element(t_stack *stack)
/*
	This function returns the last element of a stack
*/
{
	if (stack == NULL)
		return NULL;

	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

int	get_min(t_stack *stack)
/*
	This function returns the minimum value of a stack
*/
{
	int	min;

	min = stack->value;
	while (stack != NULL)
	{
        if (stack->value < min)
			min = stack->value;
        stack = stack->next;
    }
    return (min);
}

int	get_max(t_stack *stack)
/*
	This function returns the minimum value of a stack
*/
{
	int	max;

	max = stack->value;
	while (stack != NULL)
	{
        if (stack->value > max)
			max = stack->value;
        stack = stack->next;
    }
    return (max);
}

void update_indices(t_stack *stack)
/*
	This function updates all the indices of a stack
*/
{
    int index = 0;
    while (stack)
    {
        stack->index = index;
        index++;
        stack = stack->next;
    }
}

int get_stack_size(t_stack *stack)
/*
	This function returns the size of the stack
*/
{
    int size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

int ft_strisnumber(const char *str)
/*
	This function checks if a string is only composed by digits
*/
{
	if (!str || *str == '\0')
		return 0;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit((int)*str))
			return (EXIT_FAILURE);
		str++;
	}
	return (EXIT_SUCCESS);
}

void print_stack(t_stack *stack)
/*
	This function prints a stack
*/
{
	while (stack)
	{
		ft_printf("Value: %d, Index: %d\n", stack->value, stack->index);
		stack = stack->next;
	}
	ft_printf("------------------\n");
}
