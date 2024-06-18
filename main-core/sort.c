#include "push_swap.h"

void	divide_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		index_mid;
	int		count;
	t_stack	*last;

	last = last_element(*stack_a);
	index_mid = last->index / 2;
	count = 0;
	while (count <= index_mid)
	{
		pb(stack_a, stack_b);
		count++;
	}

	print_stack(*stack_a);
	print_stack(*stack_b);
}

int	is_sort(t_stack *stack)
/*
	This function checks if the stack is sorted
	Returns 0 if not
	Returns 1 if OK
*/
{
	while (stack != NULL && stack->next != NULL)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	divide_stack(stack_a, stack_b);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
	else if ((*stack_b)->value > (*stack_b)->next->value)
		sb(stack_b);
	if (is_sort(*stack_a) == 1)
	{
		print_stack(*stack_a);
	}
	else
		ft_printf("Pas trié\n");
		
}

