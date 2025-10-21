/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:32:13 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/21 14:04:26 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_put(void *num)
{
	ft_putnbr_fd(*(int *)num, 1);
	ft_putchar_fd('\n', 1);
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		sort_two(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 2)
		return (0);
	if (!init_stack_a(&stack_a, argc, argv))
	{
		ft_putstr_fd("Error.\n", 1);
		return (0);
	}
	if (is_stack_sorted(&stack_a, &stack_b))
		return (0);
	sort_stack(&stack_a, &stack_b);
	ft_lstiter(stack_a, test_put);
	ft_lstclear(&stack_a, free);
	return (0);
}
