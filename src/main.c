/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:44:51 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/16 16:34:26 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_put(void *num)
{
	ft_putnbr_fd(*(int *)num, 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (1);
	if (!init_stack_a(&stack_a, argc, argv))
	{
		ft_putstr_fd("Error.\n", 1);
		return (1);
	}
	ft_lstiter(stack_a, test_put);
	ft_lstclear(&stack_a, free);
	return (0);
}
