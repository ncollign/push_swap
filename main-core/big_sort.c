#include "push_swap.h"

int	get_upper(int value, t_stack *stack)
/*
	This function get the value of the number just upper than the value entered in param
*/
{
	int	upper;

	upper = value;
	while (stack)
	{
		if (stack->value > value)
		{
			if (upper == value && stack->value > value)
				upper = stack->value;
			else
			{
				if (stack->value < upper)
				upper = stack->value;
			}
		}
		if (!stack->next)
		{
			
			return (upper);
		}
		stack = stack->next;
	}
	return (upper);
}

int	get_cost(t_stack *stack, int upper)
{
	int cost;
	int	middle;

	cost = INT_MIN;
	middle = get_stack_size(stack) / 2;
	while (stack && cost == INT_MIN)
	{
		if (stack->value == upper)
		{
			if (stack->index >= middle)
				cost = get_stack_size(stack) - stack->index;
			else
				cost = stack->index;
		}
		else
			stack = stack->next;
	}
	return (cost);
}

int	get_cheapest(t_stack *stack_a, t_stack *stack_b)
/*
	This function find the cheapest element to move
	Returns the index of element to move in stack_b
*/
{
	int cost;
	int upper;
	int lower_cost_index;
	int	lower_cost;

	lower_cost_index = 0;
	lower_cost = INT_MAX;
	while (stack_b)
	{
		upper = get_upper(stack_b->value, stack_a);
		cost = get_cost(stack_a, upper);
		if (cost == INT_MIN)
			cost = 2;
		else
			cost += stack_b->index + 1;
		if (cost < lower_cost)
		{
			lower_cost = cost;
			lower_cost_index = stack_b->index;
		}	
		stack_b = stack_b->next;
	}
	return (lower_cost_index);
}

int	get_value_by_index(t_stack *stack, int index)
/*
	This function search an element in the stack by his index and returns his value
	Returns INT_MIN if not found
*/
{
	while (stack)
	{
		if (stack->index == index)
			return (stack->value);
		stack = stack->next;
	}
	return (INT_MIN);
}

int	get_index_by_value(t_stack *stack, int value)
/*
	This function search an element in the stack by his value and returns his index
	Returns -1 if not found
*/
{
	while (stack)
	{
		if (stack->value == value)
			return (stack->index);
		stack = stack->next;
	}
	return (-1);
}

void	divide_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	median;

	median = find_median(*stack_a);
	while (get_stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->value < median)
			pb(stack_a, stack_b);
		else
		{
			pb(stack_a, stack_b);
			rb(stack_b);
		}
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	index_to_move;
	int	value_to_move;
	int	middle_a;
	int	middle_b;
	int	value_to_place;
	int	index_to_place;

	divide_stacks(stack_a, stack_b);
	tiny_sort(stack_a);

	/*print_stack(*stack_a);
	print_stack(*stack_b);*/
	while (*stack_b)
	{
		index_to_move = get_cheapest(*stack_a, *stack_b);
		value_to_move = get_value_by_index(*stack_b, index_to_move);
		middle_b = get_stack_size(*stack_b) / 2;
		middle_a = get_stack_size(*stack_a) / 2;
		if (value_to_move > get_max(*stack_a))
			value_to_place = get_min(*stack_a);
		else
			value_to_place = get_upper(value_to_move, *stack_a);
		index_to_place = get_index_by_value(*stack_a, value_to_place);
		while (!((*stack_b)->value == value_to_move && (*stack_a)->value == value_to_place)) // Place on top
		{
			if ((*stack_b)->value != value_to_move && (*stack_a)->value != value_to_place)
			{
				if (index_to_place >= middle_a + 1 && index_to_move >= middle_b + 1)
					rrr(stack_a, stack_b);
				else if (index_to_place < middle_a + 1 && index_to_move < middle_b + 1)
					rr(stack_a, stack_b);
				else
				{
					if ((*stack_a)->value != value_to_place)
					{
						if (index_to_place >= middle_a + 1)
							rra(stack_a);
						else if (index_to_place < middle_a + 1)
							ra(stack_a);
					}
					else if ((*stack_b)->value != value_to_move)
					{
						if (index_to_move >= middle_b + 1)
							rrb(stack_b);
						else if (index_to_move < middle_b + 1)
							rb(stack_b);
					}
				}
			}
			else if ((*stack_a)->value != value_to_place)
			{
				if (index_to_place >= middle_a + 1)
					rra(stack_a);
				else if (index_to_place < middle_a + 1)
					ra(stack_a);	
			}
			else if ((*stack_b)->value != value_to_move)
			{
				if (index_to_move >= middle_b + 1)
					rrb(stack_b);
				else if (index_to_move < middle_b + 1)
					rb(stack_b);
			}
		}
		pa(stack_a, stack_b);
	}
	middle_a = get_stack_size(*stack_a) / 2;
	value_to_place = get_min(*stack_a);
	index_to_place = get_index_by_value(*stack_a, value_to_place);
	while (!is_sort(*stack_a))
	{
		if (index_to_place >= middle_a + 1)
			rra(stack_a);
		else
			ra(stack_a);
	}
}