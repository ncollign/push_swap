#include "push_swap.h"
#include <stdio.h>

void	tiny_sort(t_stack **stack)
/*
	This function sorts a stack with basic sorting
	For 1 to 3 values
	Swap elements if head is bigger than head->next
	Test if the head->next is not the minimum to avoid infinity loop
	Rotate the stack if not sorted yet
*/
{
	if (get_stack_size(*stack) == 2)
	{
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
	}
	else if (get_stack_size(*stack) == 3)
	{
		int a = (*stack)->value;
    	int b = (*stack)->next->value;
    	int c = (*stack)->next->next->value;
		if (a > b && b > c && c < a)
		{
			sa(stack);
			rra(stack);
		}
		else if (a > b && b < c && c < a)
			ra(stack);
		else if (a > b && b < c && c > a)
			sa(stack);
		else if (a < b && b > c && c < a)
			rra(stack);
		else if (a < b && b > c && c > a)
		{
			rra(stack);
			sa(stack);
		}
	}
	else
	{
		while (!is_sort(*stack))
		{
			if ((*stack)->next && (*stack)->value > (*stack)->next->value)
			{
				if (!((*stack)->value == get_max(*stack) && (*stack)->next->value == get_min(*stack)))
					sa(stack);
			}
			if (!is_sort(*stack))
				ra(stack);
		}
	}
}

void insertion_sort_array(int *array, int size)
/*
	This function sorts and array of int
*/
{
	int i;
	int j;
	int key;

	i = 1;
	while (i < size) {
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
		i++;
	}
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

int	divide_stack(t_stack **stack_a, t_stack **stack_b, int median)
/*
	This function push elements < median in stack B
	Returns the amount of operations
*/
{
	int moves;

	moves = 1;
	while (get_stack_size(*stack_a) > get_stack_size(*stack_b))
	{
		moves = 0;
		if ((*stack_a)->value < median)
		{
			if ((*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value && (*stack_a)->next->value < median)
			{
				sa(stack_a);
				moves++;
			}
			else
			{
				ra(stack_a);
				moves++;
			}
		}
		else
		{
			pb(stack_a, stack_b);
			moves++;
			if ((*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
				sb(stack_b);
		}
	}
	return (moves);
}

void	insertion_sort(t_stack **stack_a, t_stack **stack_b)
/*
	This function put elements of stack_b in stack_a in the correct order
	stack_b : reverse sorted
	Returns the amount of operations
*/
{
	while (!(is_sort(*stack_a) && is_reverse_sort(*stack_b)))
	{
		/*if (is_sort(*stack_a))
		{
			if ((*stack_b)->value < get_min(*stack_a))
				pa(stack_a, stack_b);
			else if ((*stack_b)->value > get_max(*stack_a))
			{
				pa(stack_a, stack_b);
				ra(stack_a);
			}
		}*/

		// Tri avec échanges
		if (stack_a && (*stack_a)->next && stack_b && (*stack_b)->next && (*stack_a)->value > (*stack_a)->next->value && (*stack_b)->value < (*stack_b)->next->value)
		{
			if ((*stack_a)->value != get_max(*stack_a) && (*stack_b)->value != get_min(*stack_b))
				if ((*stack_a)->next->value != get_min(*stack_a) && (*stack_b)->next->value != get_max(*stack_b))
					ss(stack_a, stack_b);
		}
		if (stack_a && (*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
		{
			if (!((*stack_a)->next->value == get_min(*stack_a) && (*stack_a)->value == get_max(*stack_a)))
				sa(stack_a);
		}
		if (stack_b && (*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
		{
			if (!((*stack_b)->next->value == get_max(*stack_b) && (*stack_b)->value == get_min(*stack_b)))
				sb(stack_b);
		}
		if (!is_sort(*stack_a))
			ra(stack_a);
		if (!is_reverse_sort(*stack_b))
			rrb(stack_b);
	}
}



void	medium_sort(t_stack **stack_a, t_stack **stack_b)
/*
	This function sorts a stack with basic sorting
	For 4 to 5 values
	Swap elements if head is bigger than head->next
	Test if the head->next is not the minimum to avoid infinity loop
	Rotate the stack if not sorted yet
*/
{
	int	median;
	int	to_push;

	if (get_stack_size(*stack_a) == 5)
	{
		to_push = 2;
		median = find_median(*stack_a);
		while (to_push > 0)
		{
			if ((*stack_a)->value > median)
			{
				pb(stack_a, stack_b);
				to_push--;
			}
			else
				ra(stack_a);
		}
		tiny_sort(stack_a);
		while (*stack_b)
			pa(stack_a, stack_b);
		tiny_sort(stack_a);
		while (!is_sort(*stack_a))
			ra(stack_a);
	}
	else
	{
		while (get_max(*stack_a) != (*stack_a)->value)
			ra(stack_a);
		pb(stack_a, stack_b);
		tiny_sort(stack_a);
		pa(stack_a, stack_b);
		while (!is_sort(*stack_a))
			ra(stack_a);
	}
}

int sort(t_stack **stack_a, t_stack **stack_b)
/*
	Main function of the sort
*/
{
	int op_count;

	op_count = 0;
	if (is_sort(*stack_a))
		return (0);
	if (get_stack_size(*stack_a) <= 3)
		tiny_sort(stack_a);		
	else if (get_stack_size(*stack_a) <= 5 && get_stack_size(*stack_a) > 3)
		medium_sort(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
	return (op_count);
}
