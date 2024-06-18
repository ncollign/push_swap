#include "push_swap.h"

int	divide_stack(t_stack **stack_a, t_stack **stack_b)
/*
	This function divides the stack_a in two equal parts, and push the half part in stack_b
	Returns the amount of operations
*/
{
	int		index_mid;
	int		index;
	t_stack	*last;

	index_mid = get_stack_size(stack_a) / 2;
	index = 0;
	while (index <= index_mid)
	{
		pb(stack_a, stack_b);
		index++;
	}
	print_stack(*stack_a);
	print_stack(*stack_b);
	return (index);
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

int	merge_stacks(t_stack **stack_a, t_stack **stack_b)
/*
	This function merges two stacks together in the right order
	stack_a is the destination stack
*/
{
	int	op_count;

	op_count = 0;
    while (*stack_b)
    {
        if ((*stack_b)->value <= (*stack_a)->value)
        {
            pa(stack_a, stack_b);
            op_count++;
        }
		ra(stack_a);
		op_count++;
    }
	return (op_count);
}

int	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		op_count;

}

void	sort(t_stack **stack_a, t_stack **stack_b)
/*
	This function sorts stacks
*/
{
	int		op_count;
	int		min;

	min = get_min(stack_a);
	op_count = 0;
	op_count += divide_stack(stack_a, stack_b);
	// Trier la pile A et B en même temps
	while (!(is_sort(*stack_a) && is_sort(*stack_b)))
	{
		if (((*stack_b)->value > (*stack_b)->next->value) && ((*stack_a)->value > (*stack_a)->next->value))
		{
			ss(stack_a, stack_b);
			op_count++;
		}
		else if ((*stack_a)->value > (*stack_a)->next->value)
		{
			sa(stack_a);
			op_count++;
		}
		else if ((*stack_b)->value > (*stack_b)->next->value)
		{	
			sb(stack_b);
			op_count++;
		}
		rrr(stack_a, stack_b);
		op_count++;
	}
	// Envoyer dans la pile A dans le bon ordre
	op_count += merge_stacks(stack_a, stack_b);


	print_stack(stack_a);
	print_stack(stack_b);
	if (is_sort(*stack_a) == 1)
	{
		print_stack(*stack_a);
		ft_printf("NB_op : %d\n", op_count);
	}
	else
		ft_printf("Pas trié\n");
}

