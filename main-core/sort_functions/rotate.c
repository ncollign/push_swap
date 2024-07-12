/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:45:32 by ncollign          #+#    #+#             */
/*   Updated: 2024/07/09 11:45:34 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack)
/*
	This function put the first element of a stack and put it at the end of the stack
*/
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = last_element(*stack);
	last->next = tmp;
	tmp->next = NULL;
	update_indices(*stack);
}

void	ra(t_stack **stack_a)
/*
	This function put the first element of stack A and put it at the end of the stack
*/
{
	if (get_stack_size(*stack_a) > 1)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
}

void	rb(t_stack **stack_b)
/*
	This function put the first element of stack B and put it at the end of the stack
*/
{
	if (get_stack_size(*stack_b) > 1)
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
/*
	This function put the first elements of stack A and B and put it at the end of each stack
*/
{
	if (get_stack_size(*stack_a) > 1 && get_stack_size(*stack_b) > 1)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
	}
}
