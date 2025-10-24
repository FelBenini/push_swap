/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:43:43 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/23 18:16:42 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target_pos(t_list *stack_a, int b_value)
{
	t_list	*current;
	int		current_value;
	int		res;
	int		i;
	int		greatest_value;

	current = stack_a;
	res = 0;
	i = 0;
	greatest_value = INT_MAX;
	while (current)
	{
		current_value = *(int *)current->content;
		current = current->next;
		if (current_value > b_value && current_value < greatest_value)
		{
			greatest_value = current_value;
			res = i;
		}
		i++;
	}
	if (greatest_value == INT_MAX)
		return (find_index_by_value(stack_a, find_min(stack_a)));
	return (res);
}

int	get_max(int value1, int value2)
{
	if (value1 > value2)
		return (value1);
	return (value2);
}

int	get_move_cost(t_list *stack_a, t_list *stack_b, int index_a, int index_b)
{
	int	size_a;
	int	size_b;
	int	cost_a;
	int	cost_b;

	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	cost_a = index_a - size_a;
	if (index_a <= size_a / 2)
		cost_a = index_a;
	cost_b = index_b - size_b;
	if (index_b <= size_b / 2)
		cost_b = index_b;
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a < 0 && cost_b < 0))
		return (get_max(ft_abs(cost_a), ft_abs(cost_b)));
	return (ft_abs(cost_a) + ft_abs(cost_b));
}
