#include "push_swap.h"

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
	while (stack != NULL && stack->next != NULL)
	{
        if (stack->value < min)
			min = stack->value;
        stack = stack->next;
    }
    return (min);
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
