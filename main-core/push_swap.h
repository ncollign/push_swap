#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

t_stack	*last_element(t_stack *stack);
void	print_stack(t_stack *stack);
int		ft_strisnumber(const char *str);
void	sort(t_stack **stack_a, t_stack **stack_b);
void	update_indices(t_stack *stack);
int		get_stack_size(t_stack *stack);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int	is_sort(t_stack *stack);

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

#endif

