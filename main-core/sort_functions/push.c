/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:45:09 by ncollign          #+#    #+#             */
/*   Updated: 2024/07/09 11:45:10 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*tmp;

	if (!stack_src || !*stack_src)
		return ;

	tmp = *stack_src;
	*stack_src = (*stack_src)->next;
	tmp->next = *stack_dest;
	*stack_dest = tmp;

	update_indices(*stack_src);
	update_indices(*stack_dest);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
/*
	This function put the first element on stack b and put it on stack a
*/
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
/*
	This function put the first element on stack a and put it on stack b
*/
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
