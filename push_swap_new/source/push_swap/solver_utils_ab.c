/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:18:50 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/13 16:14:54 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// This function calculates how many times we should rotate the stacks together.
// Because after a certain amount of rotate, we will proceed only with one 
// stack rotation.
int	ft_case_rarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = find_place_b(b, c);
	if (i < position_in_stack(a, c))
		i = position_in_stack(a, c);
	return (i);
}

// This function calculates how many times we have to rotate the stacks
// together. Since here we have reverse rotate, rather than index number,
// we check reverse index number which is calculated by lstsize - index_number.
int	ft_case_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = ft_lstsize(b) - find_place_b(b, c);
	if ((i < (ft_lstsize(a) - position_in_stack(a, c))) && position_in_stack(a, c))
		i = ft_lstsize(a) - position_in_stack(a, c);
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for rra+rb case.
int	ft_case_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (position_in_stack(a, c))
		i = ft_lstsize(a) - position_in_stack(a, c);
	i = find_place_b(b, c) + i;
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for ra+rrb case.
int	ft_case_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_b(b, c))
		i = ft_lstsize(b) - find_place_b(b, c);
	i = position_in_stack(a, c) + i;
	return (i);
}
