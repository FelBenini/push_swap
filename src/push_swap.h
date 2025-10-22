/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:03:58 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/22 15:59:38 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

int		init_stack_a(t_list **stack_a, int argc, char *argv[]);
void	swap(t_list **stack_a, t_list **stack_b, char *op);
int		is_stack_sorted(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_a, t_list **stack_b, char *op);
void	rotate(t_list **stack_a, t_list **stack_b, char *op);
void	reverse_rotate(t_list **stack_a, t_list **stack_b, char *op);
void	sort_two(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a, t_list **stack_b);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
int		find_min(t_list *stack);
int		find_position(t_list *stack, int value);
int		get_target_pos(t_list *stack_a, int b_val);

#endif
