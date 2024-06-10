/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:27:58 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/10 19:27:59 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// This function checks if the stack is sorted.
int ft_checksort(n_stack *stack_a)
{
    int i;

    if (stack_a->next == NULL)
        return (2);
    i = stack_a->nbr;
    while (stack_a)
    {
        if (i > stack_a->nbr)
            return (0);
        i = stack_a->nbr;
        stack_a = stack_a->next;
    }
    return (1);
}