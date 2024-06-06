int	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		value;
	int		index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	value = head->value;
	index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}