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

// Searching for an index in stack of 'nbr'
int cur_place(t_stack *stack, int nbr)
{
	int i;

	i = 0;
	while (stack->nbr != nbr)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

// Return an index in stack 'b' for 'nbr_push'.
// Sorting stack b in descending order.
int find_place_b(t_stack *stack_b, int nbr_push)
{
	int i;
	t_stack *tmp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < ft_lstlast(stack_b)->nbr)
		i = 0;
	else if (nbr_push > max_nbr(stack_b) || nbr_push < min_nbr(stack_b))
	{
		i = cur_place(stack_b, max_nbr(stack_b));
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

// Return an index in stack 'a' for 'nbr_push'.
// Sorting stack a in ascending order.
int find_place_a(t_stack *stack_a, int nbr_push)
{
	int i;
	t_stack *tmp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > ft_lstlast(stack_a)->nbr)
		i = 0;
	else if (nbr_push > max_nbr(stack_a) || nbr_push < min_nbr(stack_a))
		i = cur_place(stack_a, min_nbr(stack_a));
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

int min_nbr(t_stack *a)
{
	int min;

	min = a->nbr;
	while (a)
	{
		if (min > a->nbr)
			min = a->nbr;
		a = a->next;
	}
	return (min);
}

int max_nbr(t_stack *a)
{
	int max;

	max = a->nbr;
	while (a)
	{
		if (max < a->nbr)
			max = a->nbr;
		a = a->next;
	}
	return (max);
}
