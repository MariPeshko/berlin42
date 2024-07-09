/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:17:25 by mpeshko           #+#    #+#             */
/*   Updated: 2024/07/09 13:42:43 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// Pushing back from stack b to stack a. Case with both rotations (to the right)
// ft_rrr and then either ft_rra or ft_rrb
int	do_case_two_b(t_stack **b, t_stack **a, int nbr)
{
	while (cur_place((*b), nbr) != 0 && find_place_a((*a), nbr) != 0)
		ft_rrr(a, b);
	while (ft_lstsize(*b) - cur_place((*b), nbr) != ft_lstsize(*b))
		ft_rrb(b);
	while (ft_lstsize(*a) - find_place_a((*a), nbr) != ft_lstsize(*a))
		ft_rra(a);
	ft_pa(a, b);
	return (-1);
}

// Search for number of operations for pushing 'nbr' from stack b to stack a.
// Test case with both rotations (to the right) ft_rrr and
// then either ft_rra or ft_rrb. It suits when the number and its
// place both are in the end of stacks.
int	case_two_b(t_stack *b, t_stack *a, int nbr)
{
	int	operations;
	int	sz_a;
	int	sz_b;

	operations = 0;
	sz_a = ft_lstsize(a);
	sz_b = ft_lstsize(b);
	if (cur_place(b, nbr) == (sz_b - 1) && find_place_a(a, nbr) == (sz_a - 1))
		operations = 1;
	if (sz_b - cur_place(b, nbr) > sz_a - find_place_a(a, nbr))
		operations = sz_b - cur_place(b, nbr);
	if (sz_a - find_place_a(a, nbr) > sz_b - cur_place(b, nbr))
		operations = sz_a - find_place_a(a, nbr);
	return (operations);
}

// Pushing from b to a. It is the first case of operations with
// both rotations (to the left) ft_rr and then either ft_ra or ft_rb.
int	do_case_one_b(t_stack **b, t_stack **a, int nbr)
{
	while (cur_place((*b), nbr) != 0 && find_place_a((*a), nbr) != 0)
		ft_rr(a, b);
	while (cur_place((*b), nbr) != 0)
		ft_rb(b);
	while (find_place_a((*a), nbr) != 0)
		ft_ra(a);
	ft_pa(a, b);
	return (-1);
}

// Search for number of operations for pushing 'nbr' from stack b
// to stack a. A test case with both rotations (to the left)
// ft_rr and then either ft_ra or ft_rb.
int	case_one_b(t_stack *b, t_stack *a, int nbr)
{
	int	operations;

	operations = 0;
	if (cur_place(b, nbr) == find_place_a(a, nbr))
		operations = cur_place(b, nbr);
	else if (cur_place(b, nbr) > find_place_a(a, nbr))
		operations = cur_place(b, nbr);
	else if (cur_place(b, nbr) < find_place_a(a, nbr))
		operations = find_place_a(a, nbr);
	return (operations);
}

// Testing two types of instructions for all numbers in stack b.
// Variable i stands for the smallest number of operations.
int	alg_cheapest_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = case_one_b(b, a, b->nbr);
	while (tmp)
	{
		if (i > case_one_b(b, a, b->nbr))
			i = case_one_b(b, a, b->nbr);
		if (i > case_two_b(b, a, tmp->nbr))
			i = case_two_b(b, a, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
