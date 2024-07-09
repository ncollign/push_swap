/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:46:56 by ncollign          #+#    #+#             */
/*   Updated: 2024/07/09 11:46:57 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_indices(t_stack *stack)
/*
	This function updates all the indices of a stack
*/
{
	int	index;

	index = 0;
	while (stack)
	{
		stack->index = index;
		index++;
		stack = stack->next;
	}
}

int	get_stack_size(t_stack *stack)
/*
	This function returns the size of the stack
*/
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	is_sort(t_stack *stack)
/*
	This functions checks if the stack is sorted
	Returns 1 if OK
	Returns 0 if NOK
*/
{
	while (stack)
	{
		if (!stack->next && stack->value == get_min(stack))
			return (1);
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_reverse_sort(t_stack *stack)
/*
	This functions checks if the stack is reverse sorted
	Returns 1 if OK
	Returns 0 if NOK
*/
{
	while (stack)
	{
		if (!stack->next && stack->value == get_max(stack))
			return (1);
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	print_stack(t_stack *stack)
/*
	#DEBUG FUNCTION#
	This function prints a stack
*/
{
	ft_printf("------------------\n");
	while (stack)
	{
		ft_printf("Value: %d, Index: %d\n", stack->value, stack->index);
		stack = stack->next;
	}
	ft_printf("------------------\n");
}
