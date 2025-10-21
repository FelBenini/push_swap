/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:14:41 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/21 14:17:07 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget_index(t_list *lst, size_t index)
{
	size_t	i;
	t_list	*current;

	current = lst;
	i = 0;
	while (current && i < index)
	{
		current = current->next;
		i++;
	}
	return (current);
}
