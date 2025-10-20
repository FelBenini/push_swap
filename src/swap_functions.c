/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:47:38 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/16 18:10:22 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_from_stack(t_list	**stack)
{
	int	*temp;

	temp = NULL;
	if (!(*stack) || !(*stack)->content)
		return ;
	if (!(*stack)->next || !(*stack)->next->content)
		return ;
	temp = (int *)(*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
}

void	swap(t_list **stack_a, t_list **stack_b, char *op)
{
	ft_printf("%s\n", op);
	if (ft_strncmp(op, "sa", 2) == 0
		|| ft_strncmp(op, "ss", 2) == 0)
		swap_from_stack(stack_a);
	if (ft_strncmp(op, "sb", 2) == 0
		|| ft_strncmp(op, "ss", 2) == 0)
		swap_from_stack(stack_b);
}
