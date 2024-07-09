/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:46:46 by ncollign          #+#    #+#             */
/*   Updated: 2024/07/09 11:46:47 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	insertion_sort_array(int *array, int size)
/*
	This function sorts and array of int
*/
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
		i++;
	}
}

int	find_median(t_stack *stack)
/*
	This function put all the values of stack_a in an array
	Sort the array and find de median value
	Returns median value
*/
{
	t_stack	*temp;
	int		size;
	int		i;
	int		*values;
	int		median;

	size = get_stack_size(stack);
	values = (int *)malloc(size * sizeof(int));
	temp = stack;
	i = 0;
	while (i < size)
	{
		values[i] = temp->value;
		temp = temp->next;
		i++;
	}
	insertion_sort_array(values, size);
	median = values[size / 2];
	free(values);
	return (median);
}

int	get_min(t_stack *stack)
/*
	This function returns the minimum value of a stack
*/
{
	int	min;

	min = stack->value;
	while (stack != NULL)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
/*
	This function returns the minimum value of a stack
*/
{
	int	max;

	max = stack->value;
	while (stack != NULL)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}
