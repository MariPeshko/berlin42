/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:11:16 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/13 16:33:46 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// Placing the minimum number on top of stack 'a'
void sort_ascend_a(t_stack **a)
{
	int i;
	i = cur_place(*a, min_nbr(*a));

	if (i < ft_lstsize(*a) - i)
	{
		while ((*a)->nbr != min_nbr(*a))
			ft_ra(a);
	}
	else
	{
		while ((*a)->nbr != min_nbr(*a))
			ft_rra(a);
	}
}

t_stack **sort_push_to_a(t_stack **a, t_stack **b)
{
	int cheapest;
	t_stack *tmp;

	while (*b)
	{
		tmp = *b;
		cheapest = alg_cheapest_ba(*a, *b);
		while (cheapest >= 0)
		{
			if (cheapest == case_one_b(*b, *a, tmp->nbr))
					cheapest = do_case_one_b(b, a, tmp->nbr);
			else if (cheapest == case_two_b(*b, *a, tmp->nbr))
				cheapest = do_case_two_b(b, a, tmp->nbr);
			else
				tmp = tmp->next;
		}
	}
	return (a);
}

// Pushing all integers from tha stack 'a' to the stack 'b, till either
// three integers are left, or stack 'a' is sorted in ascending order.
// During each push, considering stack 'b' is sorted in descending order.
// Function 'alg_cheapest_ab' returns the smallest number of possible
// operations. In the second loop, search for the number and a case that
// matches with the smallest number of operations. 'do_case_*' functions
// make rotations and one push. Loop breaks since 'do_case_*' returns '-1'.
t_stack	*sort_push_to_b(t_stack **a, t_stack **b)
{
	int		cheapest;
	t_stack	*tmp;

	while (ft_lstsize(*a) > 3 && !check_sort(*a))
	{
		tmp = *a;
		cheapest = alg_cheapest_ab(*a, *b);
		while (cheapest >= 0)
		{
			if (cheapest == case_one(*a, *b, tmp->nbr))
				cheapest = do_case_one(a, b, tmp->nbr);
			else if (cheapest == case_two(*a, *b, tmp->nbr))
				cheapest = do_case_two(a, b, tmp->nbr);
			else
				tmp = tmp->next;
		}
	}
	return (*b);
}

void sort_algorithm(t_stack **a)
{
	t_stack *b;

	b = NULL;
	if (ft_lstsize(*a) > 3 && !check_sort(*a))
		ft_pb(a, &b);
	if (ft_lstsize(*a) > 3 && !check_sort(*a))
		ft_pb(a, &b);
	if (ft_lstsize(*a) > 3 && !check_sort(*a))
		b = sort_push_to_b(a, &b);
	if (!check_sort(*a))
		sort_three(a);
	a = sort_push_to_a(a, &b);
	sort_ascend_a(a);
}
