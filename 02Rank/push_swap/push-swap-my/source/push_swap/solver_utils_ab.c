/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:18:50 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/10 19:29:15 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// This function calculates how many times 
// we should rotate the stacks together.
// Because after a certain amount of rotate, we will
// proceed only with one stack rotation.
int ft_case_rarb(n_stack *a, n_stack *b, int c)
{
    int	i;

	i = ft_find_place_b(b, c);
    if (i < ft_find_index(a, c))
		i = ft_find_index(a, c);
	return (i);
}

// This function calculates how many times we should rotate the stacks together.
// Because after a certain amount of rotate, we will proceed only with one stack
// rotation. Since here we have reverse rotate, rather than index number,
// we check reverse index number which is 
// calculated by list_size - index_number.
int ft_case_rrarrb(n_stack *a, n_stack *b, int c)
{
	int i;

    i = 0;
	// if the place is not 0, then let'scaculate the number of rrb for right place
    if (ft_find_place_b(b, c))
	{
		i = ft_lstsize(b) - ft_find_place_b(b, c);
	}
    // Тут прорахунок операцій, скільки треба покрутити, щоб на топі опинилося
	// обране число із стеку а
    if ((i < (ft_lstsize(a) - ft_find_index(a, c))) && ft_find_index(a, c))
	    i = ft_lstsize(a) - ft_find_index(a, c);
    return (i);  
}

// Again, this function makes similar calculations.
// This function do same calculations for rra+rb case.
int	ft_case_rrarb(n_stack *a, n_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(a, c))
		i = ft_lstsize(a) - ft_find_index(a, c);
	i = ft_find_place_b(b, c) + i;
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for ra+rrb case.
int	ft_case_rarrb(n_stack *a, n_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize(b) - ft_find_place_b(b, c);
	i = ft_find_index(a, c) + i;
	return (i);
}
