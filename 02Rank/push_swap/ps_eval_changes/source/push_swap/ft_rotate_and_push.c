/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_and_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:36:34 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/13 16:07:11 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// The function ft_apply_rarb is designed to rotate the stacks such that a
// specific element 'c' is correctly positioned for a push operation.
// char 's' ndicating the direction of the push. 'a' for pushing from a to b,
// and any other character for pushing from b to a).
int	ft_apply_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && ft_find_place_b(*b, c) > 0)
			ft_rr(a, b, 0);
		while ((*a)->nbr != c)
			ft_ra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && ft_find_place_a(*a, c) > 0)
			ft_rr(a, b, 0);
		while ((*b)->nbr != c)
			ft_rb(b, 0);
		while (ft_find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

// This function rotate both stack_a and stack_b in the
// reverse direction as required amount.
// char 's' ndicating the direction of the push. 'a' for pushing from a to b,
// and any other character for pushing from b to a).
int	ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && ft_find_place_b(*b, c) > 0)
			ft_rrr(a, b, 0);
		while ((*a)->nbr != c)
			ft_rra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && ft_find_place_a(*a, c) > 0)
			ft_rrr(a, b, 0);
		while ((*b)->nbr != c)
			ft_rrb(b, 0);
		while (ft_find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

// Rotate stack 'a' until 'c' is at the top.
// Reverse rotate stack 'b' until the correct place for 'c' is at the top.
// char 's' ndicating the direction of the push. 'a' for pushing from a to b,
// and any other character for pushing from b to a).
int	ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			ft_ra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		while ((*b)->nbr != c)
			ft_rrb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

// The function ft_apply_rrarb is designed to rotate the stacks such that
// a specific element 'c' is correctly positioned for a push operation.
// Reverse rotate stack 'a' until 'c' is at the top.
// Rotate stack 'b' until the correct place for 'c' is at the top.
// char 's' ndicating the direction of the push. 'a' for pushing from a to b,
// and any other character for pushing from b to a).
int	ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			ft_rra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		while ((*b)->nbr != c)
			ft_rb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}
