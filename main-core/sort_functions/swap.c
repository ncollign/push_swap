/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:45:41 by ncollign          #+#    #+#             */
/*   Updated: 2024/07/09 11:45:43 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (get_stack_size(*stack_a) > 1)
	{
		swap(*stack_a);
		ft_printf("sa\n");
	}
}

void	sb(t_stack **stack_b)
/*
	This function swaps the elements on the top of stack b
*/
{
	if (get_stack_size(*stack_b) > 1)
	{
		swap(*stack_b);
		ft_printf("sb\n");
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
/*
	This function swaps the elements on the top of stack a and stack b
*/
{
	if (get_stack_size(*stack_a) > 1 && get_stack_size(*stack_b) > 1)
	{
		swap(*stack_a);
		swap(*stack_b);
		ft_printf("ss\n");
	}
}
