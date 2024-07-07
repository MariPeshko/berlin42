/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ba.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:01:11 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/11 18:48:29 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

int	ft_case_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = find_place_a(a, c);
	if (i < position_in_stack(b, c))
		i = position_in_stack(b, c);
	return (i);
}

int	ft_case_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	//printf("find_place_a(a, c): %i\n", find_place_a(a, c));
	if (find_place_a(a, c))
		i = ft_lstsize(a) - find_place_a(a, c);
	if ((i < (ft_lstsize(b) - position_in_stack(b, c))) && position_in_stack(b, c))
		i = ft_lstsize(b) - position_in_stack(b, c);
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for ra+rrb case.
int	ft_case_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (position_in_stack(b, c))
		i = ft_lstsize(b) - position_in_stack(b, c);
	i = find_place_a(a, c) + i;
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for rra+rb case.
int	ft_case_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (find_place_a(a, c))
		i = ft_lstsize(a) - find_place_a(a, c);
	i = position_in_stack(b, c) + i;
	return (i);
}
