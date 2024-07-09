/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:45:19 by ncollign          #+#    #+#             */
/*   Updated: 2024/07/09 11:45:23 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack **stack)
/*
	This function put the last element of a stack and put it at the beginning of the stack
*/
{
	t_stack	*tmp;
	t_stack *second_last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	second_last = *stack;
	*stack = last_element(*stack);
	while (second_last->next->next != NULL)
        second_last = second_last->next;
	second_last->next = NULL;
	(*stack)->next = tmp;
	update_indices(*stack);
}

void	rra(t_stack **stack_a)
/*
	This function put the first element of stack A and put it at the end of the stack
*/
{
	if (get_stack_size(*stack_a) > 1)
	{
		reverse_rotate(stack_a);
		ft_printf("rra\n");
	}
}

void	rrb(t_stack **stack_b)
/*
	This function put the first element of stack B and put it at the end of the stack
*/
{
	if (get_stack_size(*stack_b) > 1)
	{
		reverse_rotate(stack_b);
		ft_printf("rrb\n");
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
/*
	This function put the first elements of stack A and B and put it at the end of each stack
*/
{
	if (get_stack_size(*stack_a) > 1 && get_stack_size(*stack_b) > 1)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		ft_printf("rrr\n");
	}
}
