/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:17:36 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/21 13:24:31 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

static void	reverse_rotate_stack(t_list **stack)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rotate(t_list **stack_a, t_list **stack_b, char *op)
{
	ft_printf("%s\n", op);
	if (ft_strncmp(op, "ra", 3) == 0
		|| ft_strncmp(op, "rr", 3) == 0)
		rotate_stack(stack_a);
	if (ft_strncmp(op, "rb", 3) == 0
		|| ft_strncmp(op, "rr", 3) == 0)
		rotate_stack(stack_b);
}

void	reverse_rotate(t_list **stack_a, t_list **stack_b, char *op)
{
	ft_printf("%s\n", op);
	if (ft_strncmp(op, "rra", 4) == 0
		|| ft_strncmp(op, "rrr", 4) == 0)
		reverse_rotate_stack(stack_a);
	if (ft_strncmp(op, "rrb", 4) == 0
		|| ft_strncmp(op, "rrr", 4) == 0)
		reverse_rotate_stack(stack_b);
}
