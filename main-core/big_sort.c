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

	cost = -1;
	while (stack && cost == -1)
	{
		if (stack->value == upper)// Calculer médiane pour optimiser avec les rrb et rb
			cost = stack->index;
		stack = stack->next;
	}
	return (cost);
}

int	get_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	int cost;
	int upper;
	int lower_cost_index;
	int	lower_cost;

	lower_cost_index = 0;
	while (stack_b)
	{
		lower_cost = INT_MAX;
		upper = get_upper(stack_b->value, stack_a);
		cost = get_cost(stack_a, upper);
		if (cost == -1)
			//stack_b-> value est le max
			cost = 2; // Car on push puis on rotate
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

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	cheapest;
	while (get_stack_size(*stack_a) > 3)
	{
		pb(stack_a, stack_b);
		// A tester
		/*if ((*stack_b)->next && (*stack_b)->value < (*stack_b)->next->value)
			sb(stack_b);*/
	}
	tiny_sort(stack_a);
	while (*stack_b)
	{
		cheapest = get_cheapest(*stack_a, *stack_b);
		while (cheapest > 0)
		{
			rb(stack_b);
			cheapest--;// bouger aussi stack_a
			// Définir une target dans stack_a
		}
		pa(stack_a, stack_b);
	}
	print_stack(*stack_a);
	print_stack(*stack_b);
	

}