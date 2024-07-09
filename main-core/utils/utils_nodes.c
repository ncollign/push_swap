/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:46:33 by ncollign          #+#    #+#             */
/*   Updated: 2024/07/09 11:46:35 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*last_element(t_stack *stack)
/*
	This function returns the last element of a stack
*/
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack	*new_node(int value, int index)
/*
	This function creates a new node
*/
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	return (node);
}

int	get_value_by_index(t_stack *stack, int index)
/*
	This function search an element in the stack by his index and returns his value
	Returns INT_MIN if not found
*/
{
	while (stack)
	{
		if (stack->index == index)
			return (stack->value);
		stack = stack->next;
	}
	return (INT_MIN);
}

int	get_index_by_value(t_stack *stack, int value)
/*
	This function search an element in the stack by his value and returns his index
	Returns -1 if not found
*/
{
	while (stack)
	{
		if (stack->value == value)
			return (stack->index);
		stack = stack->next;
	}
	return (-1);
}
