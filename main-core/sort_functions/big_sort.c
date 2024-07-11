/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:44:56 by ncollign          #+#    #+#             */
/*   Updated: 2024/07/09 11:44:57 by ncollign         ###   ########.fr       */
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
*/
{
	int	cost;
	int	upper;
	int	lower_cost_index;
	int	lower_cost;
	int	size_b;

	lower_cost_index = 0;
	lower_cost = INT_MAX;
	size_b = get_stack_size(stack_b);
	while (stack_b)
	{
		upper = get_upper(stack_b->value, stack_a);
		if (upper == stack_b->value)
			upper = get_min(stack_a);
		cost = get_cost(stack_a, upper);
		if (stack_b->index >= size_b / 2 + 1)
			cost += size_b - stack_b->index;
		else
			cost += stack_b->index;
		if (cost < lower_cost)
		{
			lower_cost = cost;
			lower_cost_index = stack_b->index;
		}
		stack_b = stack_b->next;
	}
	return (lower_cost_index);
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

static void	swap_stacks(t_stack **stack_a, t_stack **stack_b)
// Il faudrait utiliser un tableau du style to_move('index', 'value')
{
	if ((*stack_a)->value != value_to_place)
	{
		if (index_to_place >= middle_a)
			rra(stack_a);
		else
			ra(stack_a);
	}
	if ((*stack_b)->value != value_to_move)
	{
		if (index_to_move >= middle_b)
			rrb(stack_b);
		else
			rb(stack_b);
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
/*
	This function sorts a stack bigger than 5 numbers
*/
{
	int	to_move[2]; // Index 0 et value 1
	int to_place[2];

	/*int	index_to_move;
	int	value_to_move;*/
	/*int	middle_a;
	int	middle_b;*/
	/*int	value_to_place;
	int	index_to_place;*/
	int	stack_a_size;
	int	stack_b_size;

	divide_stacks(stack_a, stack_b);
	tiny_sort(stack_a);

	while (*stack_b)
	{
		stack_a_size = get_stack_size(*stack_a);
		stack_b_size = get_stack_size(*stack_b);

		to_move[0] = get_cheapest(*stack_a, *stack_b);
		to_move[1] = get_value_by_index(*stack_b, to_move[0]);

		/*index_to_move = get_cheapest(*stack_a, *stack_b);
		value_to_move = get_value_by_index(*stack_b, index_to_move);*/
		//middle_b = stack_b_size / 2 + 1;
		//middle_a = stack_a_size / 2 + 1;
		if (to_move[1] > get_max(*stack_a))
			to_place[1] = get_min(*stack_a);
		else
			to_place[1] = get_upper(to_move[1], *stack_a);
		to_place[0] = get_index_by_value(*stack_a, value_to_place);
		while ((*stack_b)->value != to_move[1] || (*stack_a)->value != to_place[1])
		{
			if ((*stack_b)->value != to_move[1] && (*stack_a)->value != to_place[1])
			{
				if (to_place[0] >= stack_a_size / 2 + 1 && to_move[0] >= stack_b_size / 2 + 1)
					rrr(stack_a, stack_b);
				else if (to_place[0] < stack_a_size / 2 + 1 && to_move[0] < stack_b_size / 2 + 1)
					rr(stack_a, stack_b);
				else
				{
					swap_stacks();
					/*
					if ((*stack_a)->value != value_to_place)
					{
						if (index_to_place >= middle_a)
							rra(stack_a);
						else
							ra(stack_a);
					}
					if ((*stack_b)->value != value_to_move)
					{
						if (index_to_move >= middle_b)
							rrb(stack_b);
						else
							rb(stack_b);
					}
					*/
				}
			}
			else
			{
				swap_stacks();
				/*if ((*stack_a)->value != value_to_place)
				{
					if (index_to_place >= middle_a)
						rra(stack_a);
					else
						ra(stack_a);
				}
				if ((*stack_b)->value != value_to_move)
				{
					if (index_to_move >= middle_b)
						rrb(stack_b);
					else
						rb(stack_b);
				}*/
			}
		}
		pa(stack_a, stack_b);
	}

	//Fonction head_up()
	middle_a = get_stack_size(*stack_a) / 2 + 1;
	value_to_place = get_min(*stack_a);
	index_to_place = get_index_by_value(*stack_a, value_to_place);
	while (!is_sort(*stack_a))
	{
		if (index_to_place >= middle_a)
			rra(stack_a);
		else
			ra(stack_a);
	}
}
