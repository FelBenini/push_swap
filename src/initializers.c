/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:12:51 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/16 18:24:13 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	check_if_numbers(char **splitted_numbers)
{
	int			i;
	int			j;

	i = 0;
	while (splitted_numbers[i])
	{
		j = 0;
		if (ft_ltoi(splitted_numbers[i]) > INT_MAX
			|| ft_ltoi(splitted_numbers[i]) < INT_MIN)
			return (0);
		while (splitted_numbers[i][j])
		{
			if (!ft_isdigit(splitted_numbers[i][j]))
			{
				if (!((splitted_numbers[i][j] == '-'
						|| splitted_numbers[i][j] == '+') && j == 0))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	fill_numbers(t_list **stack_a, char *numbers)
{
	char	**splitted;
	int		i;
	int		*num;

	splitted = ft_split(numbers, ' ');
	i = 0;
	if (!check_if_numbers(splitted))
	{
		while (splitted[i])
			free(splitted[i++]);
		free(splitted);
		return (0);
	}
	i = 0;
	while (splitted[i++])
	{
		num = malloc(sizeof(int));
		*num = ft_atoi(splitted[i - 1]);
		ft_lstadd_back(stack_a, ft_lstnew(num));
	}
	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
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
	if (!check_for_dup(stack_a))
	{
		ft_lstclear(stack_a, free);
		return (0);
	}
	return (1);
}
