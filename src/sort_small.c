/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:42:40 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/22 15:18:20 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_node;

	if (ft_lstsize(*stack_a) != 2)
		return ;
	first_node = *stack_a;
	if (*(int *)(first_node->content) > *(int *)(first_node->next->content))
		swap(stack_a, stack_b, "sa");
}

void	sort_three(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	second;
	int	third;

	if (ft_lstsize(*stack_a) != 3)
		return ;
	first = *(int *)(*stack_a)->content;
	second = *(int *)(*stack_a)->next->content;
	third = *(int *)(*stack_a)->next->next->content;
	if (first > second && second < third && first < third)
		swap(stack_a, stack_b, "sa");
	else if (first > second && second > third)
	{
		swap(stack_a, stack_b, "sa");
		reverse_rotate(stack_a, stack_b, "rra");
	}
	else if (first > second && first > third)
		rotate(stack_a, stack_b, "ra");
	else if (first < second && second > third && first < third)
	{
		swap(stack_a, stack_b, "sa");
		rotate(stack_a, stack_b, "ra");
	}
	else if (first < second && second > third)
		reverse_rotate(stack_a, stack_b, "rra");
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	min_pos;

	min = find_min(*stack_a);
	min_pos = find_position(*stack_a, min);
	if (min_pos <= 2)
	{
		while (min_pos-- > 0)
			rotate(stack_a, stack_b, "ra");
	}
	else
	{
		while (min_pos++ < 4)
			reverse_rotate(stack_a, stack_b, "rra");
	}
	push(stack_a, stack_b, "pb");
	sort_three(stack_a, stack_b);
	push(stack_a, stack_b, "pa");
}

static void	sort_rest_of_five(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	min_pos;

	min = find_min(*stack_a);
	min_pos = find_position(*stack_a, min);
	if (min_pos <= 2)
	{
		while (min_pos-- > 0)
			rotate(stack_a, stack_b, "ra");
	}
	else
	{
		while (min_pos++ < 4)
			reverse_rotate(stack_a, stack_b, "rra");
	}
	push(stack_a, stack_b, "pb");
	sort_three(stack_a, stack_b);
	push(stack_a, stack_b, "pa");
	push(stack_a, stack_b, "pa");
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	min_pos;

	min = find_min(*stack_a);
	min_pos = find_position(*stack_a, min);
	if (min_pos <= 2)
	{
		while (min_pos-- > 0)
			rotate(stack_a, stack_b, "ra");
	}
	else
	{
		while (min_pos++ < 5)
			reverse_rotate(stack_a, stack_b, "rra");
	}
	push(stack_a, stack_b, "pb");
	sort_rest_of_five(stack_a, stack_b);
}
