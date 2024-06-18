#include "push_swap.h"

t_stack	*last_element(t_stack *stack)
{
	if (stack == NULL)
		return NULL;

	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return stack;
}

void update_indices(t_stack *stack)
{
    int index = 0;
    while (stack)
    {
        stack->index = index;
        index++;
        stack = stack->next;
    }
}

int ft_strisnumber(const char *str)
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
{
	while (stack)
	{
		ft_printf("Value: %d, Index: %d\n", stack->value, stack->index);
		stack = stack->next;
	}
	ft_printf("------------------\n");
}
