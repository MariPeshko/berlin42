/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:10:59 by yogun             #+#    #+#             */
/*   Updated: 2024/07/07 13:12:23 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sort_three(t_stack **stack_a)
{
	if (min_nbr(*stack_a) == (*stack_a)->nbr)
	{
		ft_rra(stack_a, 0);
		ft_sa(stack_a);
	}
	else if (max_nbr(*stack_a) == (*stack_a)->nbr)
	{
		ft_ra(stack_a);
		if (!check_sort(*stack_a))
			ft_sa(stack_a);
	}
	else
	{
		if (position_in_stack(*stack_a, max_nbr(*stack_a)) == 1)
			ft_rra(stack_a, 0);
		else
			ft_sa(stack_a);
	}
}
