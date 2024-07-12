/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:03:15 by ncollign          #+#    #+#             */
/*   Updated: 2024/07/09 14:03:17 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
			return (upper);
		stack = stack->next;
	}
	return (upper);
}

int	get_cost(t_stack *stack, int upper)
/*
	This function calculates the cost to move each element in
	the correct order from stack_b to stack_a
*/
{
	int	cost;
	int	size;

	cost = 0;
	size = get_stack_size(stack);
	while (stack)
	{
		if (stack->value == upper)
		{
			if (stack->index >= size / 2 + 1)
				cost = size - stack->index;
			else
				cost = stack->index;
			return (cost);
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
	lower :
	[0] : index
	[1] : value

	upper :
	[0] : value
	[1] : cost
*/
{
	int	upper[2];
	int	lower[2];
	int	size_b;

	lower[0] = 0;
	lower[1] = INT_MAX;
	size_b = get_stack_size(stack_b);
	while (stack_b)
	{
		upper[0] = get_upper(stack_b->value, stack_a);
		if (upper[0] == stack_b->value)
			upper[0] = get_min(stack_a);
		upper[1] = get_cost(stack_a, upper[0]);
		if (stack_b->index >= size_b / 2 + 1)
			upper[1] += size_b - stack_b->index;
		else
			upper[1] += stack_b->index;
		if (upper[1] < lower[1])
		{
			lower[1] = upper[1];
			lower[0] = stack_b->index;
		}
		stack_b = stack_b->next;
	}
	return (lower[0]);
}

void	divide_stacks(t_stack **stack_a, t_stack **stack_b)
/*
	This function push all the elements of stack_a to stack_b and let
	3 elements in stack_a
*/
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
