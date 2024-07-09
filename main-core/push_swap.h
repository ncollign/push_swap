/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:44:25 by ncollign          #+#    #+#             */
/*   Updated: 2024/07/09 11:44:29 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				index;
}				t_stack;

t_stack	*last_element(t_stack *stack);
t_stack	*new_node(int value, int index);

// UTILS
void	sort(t_stack **stack_a, t_stack **stack_b);
void	update_indices(t_stack *stack);
int		get_stack_size(t_stack *stack);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
void	ft_error(t_stack **stack_a, t_stack **stack_b);
void	free_args(char **args);
void	free_stack(t_stack **stack);
int		is_sort(t_stack *stack);
int		is_reverse_sort(t_stack *stack);
int		find_median(t_stack *stack);
int		get_value_by_index(t_stack *stack, int index);
int		get_index_by_value(t_stack *stack, int value);
int		validate_argument(char *arg);
int		ft_conversion_ok(char *start_value, int conv_value);
void	handle_argument_error(char **args, t_stack **stack_a);

// SORTING
void	big_sort(t_stack **stack_a, t_stack **stack_b);
void	tiny_sort(t_stack **stack);

// OPERATIONS
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// DEBUG
void	print_stack(t_stack *stack);

#endif
