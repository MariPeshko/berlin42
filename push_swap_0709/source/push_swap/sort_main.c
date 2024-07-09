/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:11:16 by mpeshko           #+#    #+#             */
/*   Updated: 2024/07/09 13:47:08 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// Placing the minimum number on top of stack 'a'
void	sort_ascend_a(t_stack **a)
{
	int	i;

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

// Pushing all integers from tha stack 'b' to the stack 'a'.
// During each push, considering stack 'b' is sorted in ascending order.
void	sort_push_to_a(t_stack **a, t_stack **b)
{
	int		cheapest;
	t_stack	*tmp;

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
}

// Pushing integers from tha stack 'a' to the stack 'b', till either
// three integers are left, or stack 'a' is sorted in ascending order.
// During each push, considering stack 'b' is sorted in descending order.
// Function 'alg_cheapest_ab' returns the smallest number of possible
// operations. In the second loop, search for the number and a case that
// matches with the smallest number of operations. 'do_case_*' functions
// make rotations and one push. Loop breaks since 'do_case_*' returns '-1'.
void	sort_push_to_b(t_stack **a, t_stack **b)
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
}

// Pushing all element from stack a to stack b till either
// stack a contains only three elements, or stack is sorted in
// ascending order. Whle pushing to stack b it sorts stac b in
// descending order. Then all elements from stack b are pushing back
// to stack a. Last function 'sort_ascend_a' does last sorting
// operations, the smallest element on the top, the largest
// on the bottom. Numbers are sorted!
// *** Meaning of ascening or descending order, during sorting.
// During sorting operations no need to have the smallest number on
// the top. The numbers in  stack b, for example, must be sorted correctly,
// but we don't care where is the smallest number - in the middle of the
// stack or anywhere, since the next one number either the largest one,
// or second smaller number. I imagine it as a circle of numbers.
void	sort_algorithm(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (ft_lstsize(*a) > 3 && !check_sort(*a))
		ft_pb(a, &b);
	if (ft_lstsize(*a) > 3 && !check_sort(*a))
		ft_pb(a, &b);
	if (ft_lstsize(*a) > 3 && !check_sort(*a))
		sort_push_to_b(a, &b);
	if (!check_sort(*a))
		sort_three(a);
	sort_push_to_a(a, &b);
	sort_ascend_a(a);
}
