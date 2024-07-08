/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:12:35 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/13 15:38:34 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// Pushing from a to b. Case with both rotations (to the right) ft_rrr and
// then either ft_rra or ft_rrb.
int do_case_two(t_stack **a, t_stack **b, int nbr)
{
	while (cur_place((*a), nbr) != 0 && find_place_b((*b), nbr) != 0)
		ft_rrr(a, b);
	while (ft_lstsize(*a) - cur_place((*a), nbr) != ft_lstsize(*a))
		ft_rra(a);
	while (ft_lstsize(*b) - find_place_b((*b), nbr) != ft_lstsize(*b))
		ft_rrb(b);
	ft_pb(a, b);
	return (-1);
}

// Search for number of operations for pushing 'nbr' from stack a to stack b.
// Test case with both rotations (to the right) ft_rrr and
// then either ft_rra or ft_rrb. It suits when the number and its
// place in the end of stack.
int case_two(t_stack *a, t_stack *b, int nbr)
{
	int operations;
	int sz_a;
	int sz_b;

	operations = 0;
	sz_a = ft_lstsize(a);
	sz_b = ft_lstsize(b);
	if (cur_place(a, nbr) == (sz_a - 1) && find_place_b(b, nbr) == (sz_b - 1))
		operations = 1;
	if (sz_a - cur_place(a, nbr) > sz_b - find_place_b(b, nbr))
		operations = sz_a - cur_place(a, nbr);
	if (sz_b - find_place_b(b, nbr) > sz_a - cur_place(a, nbr))
		operations = sz_b - find_place_b(b, nbr);
	return (operations);
}

// Pushing from a to b. Case with both rotations (to the left) ft_rr and
// then either ft_ra or ft_rb
int do_case_one(t_stack **a, t_stack **b, int nbr)
{
	while (cur_place((*a), nbr) != 0 && find_place_b((*b), nbr) != 0)
		ft_rr(a, b);
	while (cur_place((*a), nbr) != 0)
		ft_ra(a);
	while (find_place_b((*b), nbr) != 0)
		ft_rb(b);
	ft_pb(a, b);
	return (-1);
}

// Search for number of operations for pushing 'nbr' from stack a to stack b.
// Test case with both rotations (to the left) ft_rr and
// then either ft_ra or ft_rb
int case_one(t_stack *a, t_stack *b, int nbr)
{
	int operations;

	operations = 0;
	if (cur_place(a, nbr) == find_place_b(b, nbr))
		operations = cur_place(a, nbr);
	else if (cur_place(a, nbr) > find_place_b(b, nbr))
		operations = cur_place(a, nbr);
	else if (cur_place(a, nbr) < find_place_b(b, nbr))
		operations = find_place_b(b, nbr);
	return (operations);
}

// Testing two types of instructions for all numbers in stack a.
// Variable i stands for the smallest number of operations.
int alg_cheapest_ab(t_stack *a, t_stack *b)
{
	int i;
	t_stack *tmp;

	tmp = a;
	i = case_one(a, b, a->nbr);
	while (tmp)
	{
		if (i > case_one(a, b, tmp->nbr))
			i = case_one(a, b, tmp->nbr);
		if (i > case_two(a, b, tmp->nbr))
			i = case_two(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
