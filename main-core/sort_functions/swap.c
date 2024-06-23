#include "../push_swap.h"

static void	swap(t_stack *stack)
/*
	This function swaps The element given in argument and the element just next
*/
{
	int		tmp_value;

	if (!stack || !stack->next)
		return ;
	tmp_value = stack->next->value;
	stack->next->value = stack->value;
	stack->value = tmp_value;
}

void	sa(t_stack **stack_a)
/*
	This function swaps the elements on the top of stack a
*/
{
	swap(*stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
/*
	This function swaps the elements on the top of stack b
*/
{
	swap(*stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
/*
	This function swaps the elements on the top of stack a and stack b
*/
{
	swap(*stack_a);
	swap(*stack_b);
	ft_printf("ss\n");
}