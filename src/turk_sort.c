/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:37:00 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/23 16:59:21 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate(t_list **stack_a, t_list **stack_b)
{
	int	min_value;
	int	min_index;
	int	size;

	size = ft_lstsize(*stack_a);
	min_value = find_min(*stack_a);
	min_index = find_index_by_value(*stack_a, min_value);
	if (min_index <= size / 2)
	{
		while (min_index > 0)
		{
			rotate(stack_a, stack_b, "ra");
			min_index--;
		}
		return ;
	}
	while (min_index < size)
	{
		reverse_rotate(stack_a, stack_b, "rra");
		min_index++;
	}
}

static void	do_movement_rotations(t_list **stack_a, t_list **stack_b,
									int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rotate(stack_a, stack_b, "rr");
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		reverse_rotate(stack_a, stack_b, "rrr");
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0 && cost_a--)
		rotate(stack_a, stack_b, "ra");
	while (cost_a < 0 && cost_a++)
		reverse_rotate(stack_a, stack_b, "rra");
	while (cost_b > 0 && cost_b--)
		rotate(stack_a, stack_b, "rb");
	while (cost_b < 0 && cost_b++)
		reverse_rotate(stack_a, stack_b, "rrb");
}

void	do_best_move(t_list **stack_a, t_list **stack_b)
{
	int		best_index;
	int		target_pos;
	int		cost_a;
	int		cost_b;
	t_list	*b_node;

	if (!*stack_b)
		return ;
	best_index = find_best_move(*stack_a, *stack_b);
	b_node = ft_lstget_index(*stack_b, best_index);
	target_pos = get_target_pos(*stack_a, *(int *)b_node->content);
	cost_a = target_pos - ft_lstsize(*stack_a);
	if (target_pos <= ft_lstsize(*stack_a) / 2)
		cost_a = target_pos;
	cost_b = best_index - ft_lstsize(*stack_b);
	if (best_index <= ft_lstsize(*stack_b) / 2)
		cost_b = best_index;
	do_movement_rotations(stack_a, stack_b, cost_a, cost_b);
	push(stack_a, stack_b, "pa");
}

void	turk_sort(t_list **stack_a, t_list **stack_b)
{
	push_first_half(stack_a, stack_b);
	while (ft_lstsize(*stack_a) > 3)
		push(stack_a, stack_b, "pb");
	sort_three(stack_a, stack_b);
	while (*stack_b)
		do_best_move(stack_a, stack_b);
	final_rotate(stack_a, stack_b);
}
