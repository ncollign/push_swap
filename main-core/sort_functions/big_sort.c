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

static void	swap_stacks(t_stack **stack_a, t_stack **stack_b,
	t_sort_params *params)
// Il faudrait utiliser un tableau du style to_move('index', 'value')
{
	if ((*stack_a)->value != params->to_place[1])
	{
		if (params->to_place[0] >= params->sizes[0] / 2 + 1)
			rra(stack_a);
		else
			ra(stack_a);
	}
	if ((*stack_b)->value != params->to_move[1])
	{
		if (params->to_move[0] >= params->sizes[1] / 2 + 1)
			rrb(stack_b);
		else
			rb(stack_b);
	}
}

static void	head_up(t_stack **stack)
/*
	This function place the minimum of the stack on top of it
	Calculates de best way to do that by using ra or rra
*/
{
	int	middle_a;
	int	value_to_place;
	int	index_to_place;

	middle_a = get_stack_size(*stack) / 2 + 1;
	value_to_place = get_min(*stack);
	index_to_place = get_index_by_value(*stack, value_to_place);
	while (!is_sort(*stack))
	{
		if (index_to_place >= middle_a)
			rra(stack);
		else
			ra(stack);
	}
}

static void	sort_stacks(t_stack **stack_a, t_stack **stack_b,
	t_sort_params *params)
/*
	This function rotate the stacks by the cheapest way to sort the stacks
*/
{
	while (((*stack_b)->value != params->to_move[1])
		|| ((*stack_a)->value != params->to_place[1]))
	{
		if (((*stack_b)->value != params->to_move[1])
			&& ((*stack_a)->value != params->to_place[1]))
		{
			if ((params->to_place[0] >= params->sizes[0] / 2 + 1)
				&& (params->to_move[0] >= params->sizes[1] / 2 + 1))
				rrr(stack_a, stack_b);
			else if ((params->to_place[0] < params->sizes[0] / 2 + 1)
				&& (params->to_move[0] < params->sizes[1] / 2 + 1))
				rr(stack_a, stack_b);
			else
				swap_stacks(stack_a, stack_b, params);
		}
		else
			swap_stacks(stack_a, stack_b, params);
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
/*
	This function sorts a stack bigger than 5 numbers
	to_move et to_place :
	[0] : index
	[1] : value

	sizes :
	[0] : size of stack_a
	[1] : size of stack_b
*/
{
	t_sort_params	params;

	divide_stacks(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		params.sizes[0] = get_stack_size(*stack_a);
		params.sizes[1] = get_stack_size(*stack_b);
		params.to_move[0] = get_cheapest(*stack_a, *stack_b);
		params.to_move[1] = get_value_by_index(*stack_b, params.to_move[0]);
		if (params.to_move[1] > get_max(*stack_a))
			params.to_place[1] = get_min(*stack_a);
		else
			params.to_place[1] = get_upper(params.to_move[1], *stack_a);
		params.to_place[0] = get_index_by_value(*stack_a, params.to_place[1]);
		sort_stacks(stack_a, stack_b, &params);
		pa(stack_a, stack_b);
	}
	head_up(stack_a);
}
