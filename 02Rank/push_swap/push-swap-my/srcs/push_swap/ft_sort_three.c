/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:27:33 by mpeshko           #+#    #+#             */
/*   Updated: 2024/05/15 16:38:13 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// This function sort the stack if there are only
// three elements in the stack.
void ft_sort_three(n_stack **stack_a)
{
    printf("In ft_sort_three\n");
    if (ft_min(*stack_a) == (*stack_a)->nbr)
    {
        ft_rra(stack_a, 0);
        ft_sa(stack_a, 0);
    }
    else if (ft_max(*stack_a) == (*stack_a)->nbr)
    {
        ft_ra(stack_a, 0);
        if (!ft_checksort(*stack_a))
            ft_sa(stack_a, 0);
    }
    else if (ft_min(*stack_a) == (*stack_a)->next->nbr)
        ft_sa(stack_a, 0);
    else
        ft_rra(stack_a, 0);
}