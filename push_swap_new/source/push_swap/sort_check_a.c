/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:48:06 by mpeshko           #+#    #+#             */
/*   Updated: 2024/07/05 11:48:06 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// It checks if the stack is correctly sorted in ascending order.
// If the stack is not sorted it returns 0.
int	check_sort(t_stack *stack)
{
	int	prev_nbr;

	if (!stack)
		return (0);
	prev_nbr = stack->nbr;
	stack = stack->next;
	while (stack)
	{
		if (prev_nbr > stack->nbr)
			return (0);
		prev_nbr = stack->nbr;
		stack = stack->next;
	}
	return (3);
}
