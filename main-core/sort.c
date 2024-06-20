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

	index_mid = get_stack_size(*stack_a) / 2;
	index = 0;
	while (index < index_mid)
	{
		pb(stack_a, stack_b);
		index++;
	}
	return (index);
}

int	is_sort(t_stack *stack)
/*
	This function checks if the stack is sorted circularly
	Returns 0 if not
	Returns 1 if OK
*/
{
	int	min;
	int	max;
	int	head_value;

	min = get_min(stack);
	max = get_max(stack);
	head_value = stack->value;
	while (stack != NULL && stack->next != NULL)
    {
        if (stack->value > stack->next->value)
		{
			if (!(stack->value == max && stack->next->value == min))
				return (0);
		}
        stack = stack->next;
		if (stack->next == NULL && (stack->value > head_value))
		{
			if (!(stack->value == max && head_value == min))
				return(0);
		}
    }
    return (1);
}

int	heads_top(t_stack **stack_a, t_stack **stack_b)
/*
	This function puts the heads of the stacks on the top of them
*/
{
	int	min_a;
	int	min_b;
	int	op_count;

	min_a = get_min(*stack_a);
	min_b = get_min(*stack_b);
	op_count = 0;
	while (((*stack_a)->value != min_a) || ((*stack_b)->value != min_b))
	{
		if ((*stack_a)->value == min_a)
			rb(stack_b);
		else if ((*stack_b)->value == min_b)
			ra(stack_a);
		else
			rr(stack_a, stack_b);
		op_count++;
	}
	return (op_count);
}

int	merge_stacks(t_stack **stack_a, t_stack **stack_b)
/*
	This function merges two stacks together in the right order
	Put the head on the top of stack A
	stack_a is the destination stack
*/
{
	int	min;
	int	op_count;

	op_count = 0;
    while (*stack_b)
    {
        if ((*stack_b)->value <= (*stack_a)->value)
        {
            pa(stack_a, stack_b);
            op_count++;
        }
		else if ((*stack_a)->value == get_max(*stack_a))
		{
			ra(stack_a);
			pa(stack_a, stack_b);
			op_count++;
		}
		ra(stack_a);
		op_count++;
    }
	min = get_min(*stack_a);
	while ((*stack_a)->value != min)
	{
		ra(stack_a);
		op_count++;
	}
	return (op_count);
}

int simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	op_count;
	int	max_a;
	int	max_b;
	int	is_sorted;

	op_count = 0;
	is_sorted = 0;
	max_a = get_max(*stack_a);
	max_b = get_max(*stack_b);
    while (is_sorted == 0)
    {
        if (((*stack_b)->value > (*stack_b)->next->value) && ((*stack_a)->value > (*stack_a)->next->value))
		{
			if ((*stack_a)->value != max_a && (*stack_b)->value != max_b)
			{
				ss(stack_a, stack_b);
				op_count++;
			}
		}
		else
		{
			if ((*stack_a)->value > (*stack_a)->next->value && (*stack_a)->value != max_a)
			{
				sa(stack_a);
				op_count++;
			}
			if ((*stack_b)->value > (*stack_b)->next->value && (*stack_b)->value != max_b)
			{
				sb(stack_b);
				op_count++;
			}
		}
		if (is_sort(*stack_a) && !is_sort(*stack_b))
        {
            rb(stack_b);
            op_count++;
        }
        else if (is_sort(*stack_b) && !is_sort(*stack_a))
        {
            ra(stack_a);
            op_count++;
        }
		else if (!is_sort(*stack_a) && !is_sort(*stack_b))
		{
			rr(stack_a, stack_b);
			ft_printf("OK");
            op_count++;
		}
		else
			is_sorted = 1;
		
    }
	return (op_count);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
/*
	This function sorts stacks
*/
{
	int		op_count;
	
	op_count = 0;
	op_count += divide_stack(stack_a, stack_b);
	// Sort stack A and B simultaneously
	op_count += simple_sort(stack_a, stack_b);
	op_count += heads_top(stack_a, stack_b);
	// Envoyer dans la pile A dans le bon ordre
	op_count += merge_stacks(stack_a, stack_b);
	
	print_stack(*stack_a);
	if (is_sort(*stack_a) == 1)
	{
		//print_stack(*stack_a);
		ft_printf("NB_op : %d\n", op_count);
	}
	else
		ft_printf("Pas trié\n");
}

