#include "../main-core/push_swap.h"

static void	reverse_rotate(t_stack **stack)
/*
	This function put the first element of a stack and put it at the end of the stack
*/
{
	t_stack	*tmp;
	t_stack *last;
	int		index;

	if (!*stack)
		return ;
	last = last_element(*stack);
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;

	last = last_element(*stack);
	last->next = NULL;





	
	/*tmp = *stack;
	*stack = (*stack)->next;
	last = last_element(*stack);
	last->next = tmp;
	tmp->next = NULL;*/
	
	/*
	index = 0;
	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
	last->next->index = index;
	*/
}

void	rra(t_stack **stack_a)
/*
	This function put the first element of stack A and put it at the end of the stack
*/
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack_b)
/*
	This function put the first element of stack B and put it at the end of the stack
*/
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
/*
	This function put the first elements of stack A and B and put it at the end of each stack
*/
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}