/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:55:18 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/13 16:30:37 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// This function checks the index of a number in the stack.
// This function calculates the index (or the number of rotations needed)
// to bring the element 'nbr' to the top of stack (for example, a).
int	ft_find_index(t_stack *st, int nbr)
{
	int	i;

	i = 0;
	while (st->nbr != nbr)
	{
		i++;
		st = st->next;
	}
	return (i);
}

// This function calculates the number of rotations needed to place
// the element 'nbr_push' into its correct position in stack b. The goal is
// to place elements in stack b in descending order.
// 1. Check if 'nbr_push' should be placed at the beginning of the stack.
// 2. Check if 'nbr_push' is outside the current max and min bounds.
// 3. Find the correct position for 'nbr_push'. Continue rotating (i++)
// while the current element'stack_b->nbr' is less than 'nbr_push' or
// the next element 'tmp->nbr' is greater than nbr_push.
int	ft_find_place_b(t_stack *stack_b, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < ft_lstlast(stack_b)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
	{
		i = ft_find_index(stack_b, ft_max(stack_b));
		return (i);
	}
	else
	{
		tmp = stack_b->next;
		while (nbr_push > stack_b->nbr || nbr_push < tmp->nbr)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

// This function calculates the number of rotations needed to place the element
// 'nbr_push' into its correct position in stack 'a'.
// 1. Check if 'nbr_push' should be placed at the beginning of the stack.
// 2. Check if 'nbr_push' is outside the current min and max bounds.
// 3. Find the correct position for 'nbr_push'. Continue rotating (i++)
// while the current element stack_a->nbr is greater than nbr_push
// or the next element tmp->nbr is less than nbr_push.
int	ft_find_place_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > ft_lstlast(stack_a)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
