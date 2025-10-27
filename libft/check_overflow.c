/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenini- <fbenini-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:02:53 by fbenini-          #+#    #+#             */
/*   Updated: 2025/10/27 14:04:21 by fbenini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	check_overflow(char *str)
{
	long int	lnum;

	lnum = ft_ltoi(str);
	if (lnum > INT_MAX || lnum < INT_MIN)
		return (0);
	return (1);
}
