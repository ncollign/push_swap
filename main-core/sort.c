#include "push_swap.h"
#include <stdio.h>

void insertion_sort_array(int *array, int size) {
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = array[i];
		j = 0;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

int insertion_sort(t_stack **stack_a, t_stack **stack_b)
/*
	This function put elements of stack_b in stack_a in the correct order
	Returns the amount of operations
*/
{
	int	op_count;

	op_count = 0;
	/*while (*stack_a && (*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
	{
		sa(stack_a);
		
		*stack_a = (*stack_a)->next;
	}*/

	while (!(is_sort(stack_a) && is_sort(stack_b)))
	{
		if ((*stack_a)->value > (*stack_a)->next->value && (*stack_b)->value > (*stack_b)->next->value)
		{
			ss(stack_a, stack_b);
		}
		else if ((*stack_a)->value > (*stack_a)->next->value)
		{
			sa(stack_a);
		}
		else if ((*stack_b)->value > (*stack_b)->next->value)
		{
			sb(stack_b);
		}
		rr(stack_a, stack_b);
	}
	return (op_count);
}


int find_median(t_stack *stack)
/*
	This function put all the values of stack_a in an array
	Sort the array and find de median value
	Returns median value
*/
{
	int size;
	int	i;
	int *values;
	int median;
	t_stack *temp;

	size = get_stack_size(stack);
	values = (int *)malloc(size * sizeof(int));
	temp = stack;
	i = 0;
	while (i < size)
	{
		values[i] = temp->value;
		temp = temp->next;
		i++;
	}
	insertion_sort_array(values, size);
	median = values[size / 2];
	free(values);
	return (median);
}

int divide_stack(t_stack **stack_a, t_stack **stack_b, int median)
/*
	This function push elements < median in stack B
	Returns the amount of operations
*/
{
	int size;
	int op_count;
	int	i;
	
	size = get_stack_size(*stack_a);
	op_count = 0;
	i = 0;
	while (i < size)
	{
		if ((*stack_a)->value < median)
		{
			pb(stack_a, stack_b);
			op_count++;
		}
		else
		{
			ra(stack_a);
			op_count++;
		}
		i++;
	}
	return (op_count);
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

// Fonction principale de tri
void sort(t_stack **stack_a, t_stack **stack_b) {
	int median;
	int moves;
	
	if (is_sort(*stack_a)) {
		return ;
	}
	moves = 1;
	while (!is_sort(*stack_a) && moves != 0)
	{
		median = find_median(*stack_a);
		moves = divide_stack(stack_a, stack_b, median);
	}
	insertion_sort(stack_a, stack_b);
}
