/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:12:51 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/27 15:29:54 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	check_if_numbers(char **splitted_numbers)
{
	int		i;
	int		j;

	i = 0;
	while (splitted_numbers[i])
	{
		j = 0;
		if (splitted_numbers[i][j] == '+' || splitted_numbers[i][j] == '-')
		{
			if (!splitted_numbers[i][j + 1])
				return (0);
			j++;
		}
		while (splitted_numbers[i][j++])
		{
			if (!ft_isdigit(splitted_numbers[i][j - 1]))
				return (0);
		}
		if (!check_overflow(splitted_numbers[i]))
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

static int	count_numbers_on_list(t_list **stack_a, int num)
{
	int		count;
	t_list	*current;
	int		current_number;

	count = 0;
	current = *stack_a;
	while (current)
	{
		current_number = *(int *)current->content;
		if (current_number == num)
			count++;
		current = current->next;
	}
	return (count);
}

static int	check_for_dup(t_list **stack_a)
{
	int		current_number;
	t_list	*current;

	current = *stack_a;
	while (current)
	{
		current_number = *(int *)current->content;
		if (count_numbers_on_list(stack_a, current_number) > 1)
			return (0);
		current = current->next;
	}
	return (1);
}

int	init_stack_a(t_list **stack_a, int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!fill_numbers(stack_a, argv[i]))
		{
			ft_lstclear(stack_a, free);
			return (0);
		}
		i++;
	}
	if (ft_lstsize(*stack_a) == 0)
		return (0);
	if (!check_for_dup(stack_a))
	{
		ft_lstclear(stack_a, free);
		return (0);
	}
	return (1);
}
