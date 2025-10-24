/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 13:01:17 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/21 13:01:29 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("%s\n", op);
	if (ft_strncmp(op, "pa", 2) == 0)
		push_from_stack(stack_b, stack_a);
	if (ft_strncmp(op, "pb", 2) == 0)
		push_from_stack(stack_a, stack_b);
}

static void	do_push_half(t_list **stack_a, t_list **stack_b,
						int median, int size)
{
	int	i;
	int	pushed;
	int	current;
	int	max;
	int	min;

	i = 0;
	pushed = 0;
	min = find_min(*stack_a);
	max = find_max(*stack_a);
	while (pushed < size / 2 && i < size)
	{
		current = *(int *)(*stack_a)->content;
		if (current != min && current != max && current < median)
		{
			push(stack_a, stack_b, "pb");
			pushed++;
		}
		else
			rotate(stack_a, stack_b, "ra");
		i++;
	}
}

void	push_first_half(t_list **stack_a, t_list **stack_b)
{
	int		median;
	int		size;

	median = find_median(*stack_a);
	ft_printf("%d\n", median);
	size = ft_lstsize(*stack_a);
	do_push_half(stack_a, stack_b, median, size);
}
