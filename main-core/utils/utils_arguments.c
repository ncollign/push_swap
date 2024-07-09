/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:03:15 by ncollign          #+#    #+#             */
/*   Updated: 2024/07/09 14:03:17 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_argument_error(char **args, t_stack **stack_a)
/*
	This function handle errors with arguments
	Free the arguments and the stack_a
*/
{
	free_args(args);
	ft_error(stack_a, stack_a);
}

int	ft_conversion_ok(char *start_value, int conv_value)
/*
	This function compares the value of the conversion and the initial value
	Returns 0 if OK
	Returns 1 if NOK
*/
{
	char	*str_conv_value;

	str_conv_value = ft_itoa(conv_value);
	if (ft_strncmp(str_conv_value, start_value, ft_strlen(start_value)))
	{
		free(str_conv_value);
		return (EXIT_FAILURE);
	}
	else
	{
		free(str_conv_value);
		return (EXIT_SUCCESS);
	}
}

int	validate_argument(char *arg)
/*
	This functions validates if an argument is OK
	Returns 1 if NOK
	Returns 0 if OK
*/
{
	int	j;

	j = 0;
	while (arg[j])
	{
		if (!ft_isdigit((int)arg[j]) && (arg[j] != '-' || j != 0))
			return (1);
		j++;
	}
	return (0);
}
