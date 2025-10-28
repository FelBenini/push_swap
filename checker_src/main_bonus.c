/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:32:45 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/27 12:27:16 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static t_operations	*return_operation(char *op)
{
	size_t				num_maps;
	size_t				i;
	static t_operations	operations[] = {
	{"pa\n", push},
	{"pb\n", push},
	{"sa\n", swap},
	{"sb\n", swap},
	{"ss\n", swap},
	{"ra\n", rotate},
	{"rb\n", rotate},
	{"rr\n", rotate},
	{"rra\n", reverse_rotate},
	{"rrb\n", reverse_rotate},
	{"rrr\n", reverse_rotate},
	};

	num_maps = sizeof(operations) / sizeof(t_operations);
	i = 0;
	while (i < num_maps)
	{
		if (ft_strncmp(operations[i].key, op, 4) == 0)
			return (&operations[i]);
		i++;
	}
	return (NULL);
}

static int	read_input(char **line)
{
	char	*buffer;
	int		i;
	int		bytes_read;
	char	ch;
	int		buffer_size;

	buffer_size = BUFFER_SIZE;
	buffer = (char *)malloc(buffer_size);
	i = 0;
	bytes_read = read(STDIN_FILENO, &ch, 1);
	while (bytes_read > 0 && ch != '\n' && ch != '\0')
	{
		if (i >= buffer_size - 1)
			buffer_size *= 2;
		if (i >= buffer_size - 1)
			buffer = (char *)ft_realloc(buffer, buffer_size);
		buffer[i++] = ch;
		bytes_read = read(0, &ch, 1);
	}
	if (bytes_read > 0)
		buffer[i++] = '\n';
	buffer[i] = '\0';
	*line = buffer;
	return (1);
}

static int	read_stdin(t_list **stack_a, t_list **stack_b)
{
	char			*line;
	t_operations	*operation;

	while (read_input(&line))
	{
		if (!line || line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			break ;
		}
		operation = return_operation(line);
		if (operation)
			operation->function(stack_a, stack_b, line);
		free(line);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!init_stack_a(&stack_a, argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!read_stdin(&stack_a, &stack_b))
	{
		ft_lstclear(&stack_a, free);
		ft_lstclear(&stack_b, free);
		return (1);
	}
	if (!is_stack_sorted(&stack_a, &stack_b))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
	return (0);
}
