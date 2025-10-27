/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:12:13 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/27 15:30:06 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_splitted(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

static int	insert_numbers_into_stack(t_list **stack_a, char **splitted)
{
	int		*num;
	t_list	*node;
	int		i;

	i = 0;
	while (splitted[i++])
	{
		num = malloc(sizeof(int));
		if (!num)
			return (0);
		*num = ft_atoi(splitted[i - 1]);
		node = ft_lstnew(num);
		if (!node)
		{
			free(num);
			return (0);
		}
		ft_lstadd_back(stack_a, node);
	}
	return (1);
}

int	fill_numbers(t_list **stack_a, char *numbers)
{
	char	**splitted;

	splitted = ft_split(numbers, ' ');
	if (!splitted)
		return (0);
	if (!check_if_numbers(splitted))
	{
		clear_splitted(splitted);
		return (0);
	}
	if (!insert_numbers_into_stack(stack_a, splitted))
	{
		clear_splitted(splitted);
		return (0);
	}
	clear_splitted(splitted);
	return (1);
}
