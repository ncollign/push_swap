/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:45:58 by ncollign          #+#    #+#             */
/*   Updated: 2024/07/09 11:46:01 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static void	swap_elements(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
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
		swap_elements(stack);
	else
	{
		while (!is_sort(*stack))
		{
			if ((*stack)->next && (*stack)->value > (*stack)->next->value)
			{
				if (!(((*stack)->value == get_max(*stack))
						&& ((*stack)->next->value == get_min(*stack))))
					sa(stack);
			}
			if (!is_sort(*stack))
				ra(stack);
		}
	}
}
