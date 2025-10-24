/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_finders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:55:54 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/23 20:48:23 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *stack)
{
	int	min;
	int	current;

	if (!stack)
		return (0);
	min = *(int *)stack->content;
	while (stack)
	{
		current = *(int *)stack->content;
		if (current < min)
			min = current;
		stack = stack->next;
	}
	return (min);
}

int	find_max(t_list *stack)
{
	int	max;
	int	current;

	if (!stack)
		return (0);
	max = *(int *)stack->content;
	while (stack)
	{
		current = *(int *)stack->content;
		if (current > max)
			max = current;
		stack = stack->next;
	}
	return (max);
}

int	find_median(t_list *stack)
{
	int		*arr;
	int		stack_size;
	int		res;
	int		i;
	t_list	*current;

	stack_size = ft_lstsize(stack);
	arr = malloc(stack_size * sizeof(int));
	current = stack;
	i = 0;
	while (current)
	{
		arr[i] = *(int *)current->content;
		current = current->next;
		i++;
	}
	ft_sort_int_tab(arr, stack_size);
	res = arr[stack_size / 2];
	free(arr);
	return (res);
}

int	find_index_by_value(t_list *stack, int value)
{
	int	current;
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		current = *(int *)stack->content;
		if (current == value)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}

int	find_best_move(t_list *stack_a, t_list *stack_b)
{
	t_list	*current;
	int		best_index;
	int		index_b;
	int		best_cost;
	int		current_cost;

	current = stack_b;
	best_index = 0;
	best_cost = INT_MAX;
	index_b = 0;
	while (current)
	{
		current_cost = get_move_cost(stack_a, stack_b,
				get_target_pos(stack_a, *(int *)current->content),
				index_b);
		current = current->next;
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best_index = index_b;
		}
		index_b++;
	}
	return (best_index);
}
