/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:20:48 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/27 12:21:54 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	push_from_stack(t_list **src, t_list **dest)
{
	t_list	*temp;

	if (!src || !(*src))
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	push(t_list **stack_a, t_list **stack_b, char *op)
{
	if (ft_strncmp(op, "pa", 2) == 0)
		push_from_stack(stack_b, stack_a);
	if (ft_strncmp(op, "pb", 2) == 0)
		push_from_stack(stack_a, stack_b);
}
