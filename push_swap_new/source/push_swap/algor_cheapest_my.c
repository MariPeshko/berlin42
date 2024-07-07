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

int ft_rotate_type_ba(t_stack *a, t_stack *b)
{
	int i;
	t_stack *tmp;

	tmp = b;
	i = ft_case_rrarrb_a(a, b, b->nbr);
	// printf("ft_rotate_type_ba. ft_case_rrarrb_a. i: %i\n", i);
	while (tmp)
	{
		if (i > ft_case_rarb_a(a, b, tmp->nbr))
			i = ft_case_rarb_a(a, b, tmp->nbr);
		if (i > ft_case_rrarrb_a(a, b, tmp->nbr))
			i = ft_case_rrarrb_a(a, b, tmp->nbr);
		if (i > ft_case_rarrb_a(a, b, tmp->nbr))
			i = ft_case_rarrb_a(a, b, tmp->nbr);
		if (i > ft_case_rrarb_a(a, b, tmp->nbr))
			i = ft_case_rrarb_a(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

// first case of operations for pushing from a to b.
// case with both rotations (to the left) ft_rr and
// then either ft_ra or ft_rb
int do_case_one_b(t_stack **a, t_stack **b, int nbr)
{
	printf("do_case_one for %i\n", nbr);
	while (position_in_stack((*b), nbr) != 0 && find_place_b((*a), nbr) != 0)
		ft_rr(a, b);
	while (position_in_stack((*b), nbr) != 0)
		ft_ra(a);
	while (find_place_a((*a), nbr) != 0)
		ft_rb(b);
	ft_pa(a, b);
	return (-1);
}

// first case of operations for pushing from a to b.
// case with both rotations (to the left) ft_rr and
// then either ft_ra or ft_rb
int do_case_one(t_stack **a, t_stack **b, int nbr)
{
	printf("do_case_one for %i\n", nbr);
	while (position_in_stack((*a), nbr) != 0 && find_place_b((*b), nbr) != 0)
		ft_rr(a, b);
	while (position_in_stack((*a), nbr) != 0)
		ft_ra(a);
	while (find_place_b((*b), nbr) != 0)
		ft_rb(b);
	ft_pb(a, b);
	return (-1);
}

// test case with both rotations (to the left) ft_rr and
// then either ft_ra or ft_rb
int case_one(t_stack *a, t_stack *b, int nbr)
{
	// printf("caseone, number: %i\n", nbr);
	// printf("find_place_b(b, %i): %i\n", nbr, find_place_b(b, nbr));
	int operations;
	int both;

	operations = 0;
	if (position_in_stack(a, nbr) == find_place_b(b, nbr))
		operations = position_in_stack(a, nbr);
	else if (position_in_stack(a, nbr) > find_place_b(b, nbr))
	{
		both = find_place_b(b, nbr);
		operations = both + (position_in_stack(a, nbr) - both);
	}
	else if (position_in_stack(a, nbr) < find_place_b(b, nbr))
	{
		both = position_in_stack(a, nbr);
		operations = both + (find_place_b(b, nbr) - both);
	}
	return (operations);
}

int alg_cheapest_ab(t_stack *a, t_stack *b, int *index)
{
	int i;
	int ind;
	int cost;
	t_stack *tmp;

	tmp = a;
	ind = 0;
	i = case_one(a, b, a->nbr);
	printf("case_one: %i\n", i);
	cost = i;
	while (tmp)
	{
		// printf("nbr: %i\n", tmp->nbr);

		if (i > ft_case_rarb(a, b, tmp->nbr))
			i = ft_case_rarb(a, b, tmp->nbr);
		if (i > ft_case_rrarrb(a, b, tmp->nbr))
			i = ft_case_rrarrb(a, b, tmp->nbr);
		if (i > ft_case_rarrb(a, b, tmp->nbr))
			i = ft_case_rarrb(a, b, tmp->nbr);
		if (i > ft_case_rrarb(a, b, tmp->nbr))
			i = ft_case_rrarb(a, b, tmp->nbr);
		if (i < cost)
		{
			cost = i;
			*index = ind;
		}
		ind++;
		tmp = tmp->next;
	}
	return (i);
}

// int choose_type_10_plus(t_stack *a, t_stack *b)
// {
// 	int i;
// 	t_stack *tmp;
// 	int fivefive;

// 	fivefive = 5;
// 	tmp = a;
// 	i = ft_case_rrarrb(a, b, a->nbr);
// 	while (tmp && fivefive >= 1)
// 	{
// 		// fprintf(stderr, "checkfor %i\n", tmp->nbr);
// 		if (i > ft_case_rarb(a, b, tmp->nbr))
// 			i = ft_case_rarb(a, b, tmp->nbr);
// 		if (i > ft_case_rrarrb(a, b, tmp->nbr))
// 			i = ft_case_rrarrb(a, b, tmp->nbr);
// 		if (i > ft_case_rarrb(a, b, tmp->nbr))
// 			i = ft_case_rarrb(a, b, tmp->nbr);
// 		if (i > ft_case_rrarb(a, b, tmp->nbr))
// 			i = ft_case_rrarb(a, b, tmp->nbr);
// 		tmp = tmp->next;
// 		fivefive--;
// 	}
// 	return (i);
// }
