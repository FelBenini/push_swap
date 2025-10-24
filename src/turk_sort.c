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

void	turk_sort(t_list **stack_a, t_list **stack_b)
{
	push_first_half(stack_a, stack_b);
}
