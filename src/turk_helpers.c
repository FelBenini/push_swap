#include "push_swap.h"

static int	find_first_pos_greater(t_list *stack_a, int b_val)
{
	int		curr;
	t_list	*current;
	int		pos;

	current = stack_a;
	pos = 0;
	while (current)
	{
		curr = *(int *)current->content;
		if (b_val < curr)
			return (pos);
		pos++;
		current = current->next;
	}
	return (0);
}

int	get_target_pos(t_list *stack_a, int b_val)
{
	int		min_val;
	int		max_val;
	t_list	*current;

	if (!stack_a)
		return (0);
	min_val = find_min(stack_a);
	max_val = *(int *)stack_a->content;
	current = stack_a;
	while (current)
	{
		if (*(int *)current->content > max_val)
			max_val = *(int *)current->content;
		current = current->next;
	}
	if (b_val < min_val || b_val > max_val)
		return (find_position(stack_a, min_val));
	return (find_first_pos_greater(stack_a, b_val));
}

