/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:07:12 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/20 19:13:11 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	is_stack_sorted(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		previous_value;

	current = *stack_a;
	if (ft_lstsize(*stack_b) > 0)
		return (0);
	previous_value = *(int *)current->content;
	current = current->next;
	while (current)
	{
		if (*(int *)current->content < previous_value)
			return (0);
		previous_value = *(int *)current->content;
		current = current->next;
	}
	return (1);
}
