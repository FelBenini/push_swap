/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:03:58 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/20 19:10:41 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

int		init_stack_a(t_list **stack_a, int argc, char *argv[]);
void	swap(t_list **stack_a, t_list **stack_b, char *op);
int		is_stack_sorted(t_list **stack_a, t_list **stack_b);

#endif
