/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_finders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:55:54 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/22 16:00:50 by fbenini-         ###   ########.fr       */
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

int	find_position(t_list *stack, int value)
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
