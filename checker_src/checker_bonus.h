/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:43:27 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/27 12:12:37 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"

typedef struct s_operations {
	char	*key;
	void	(*function)(t_list **stack_a, t_list **stack_b, char *op);
}	t_operations;

int		init_stack_a(t_list **stack_a, int argc, char *argv[]);
int		is_stack_sorted(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack_a, t_list **stack_b, char *op);
void	push(t_list **stack_a, t_list **stack_b, char *op);
void	rotate(t_list **stack_a, t_list **stack_b, char *op);
void	reverse_rotate(t_list **stack_a, t_list **stack_b, char *op);

#endif
