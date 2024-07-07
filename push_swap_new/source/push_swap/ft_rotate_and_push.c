/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_and_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:36:34 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/13 16:07:11 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

int	ft_apply_rarb(t_stack **a, t_stack **b, int c, char s)
{
	//fprintf(stderr, "apply_rarb\n");
	if (s == 'a')
	{
		while ((*a)->nbr != c && find_place_b(*b, c) > 0)
			ft_rr(a, b);
		while ((*a)->nbr != c)
			ft_ra(a);
		while (find_place_b(*b, c) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while ((*b)->nbr != c && find_place_a(*a, c) > 0)
			ft_rr(a, b);
		while ((*b)->nbr != c)
			ft_rb(b);
		while (find_place_a(*a, c) > 0)
			ft_ra(a);
		ft_pa(a, b);
	}
	return (-1);
}

int	ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	//fprintf(stderr, "apply_rrarrb\n");

	t_stack *tmp;
	tmp = *a;

	while(tmp)
	{
		//fprintf(stderr, "a: %i\n", tmp->nbr);
		tmp = tmp->next;
	}
	//fprintf(stderr, "nbr to push: %i\n", c);

	if (s == 'a')
	{
		while ((*a)->nbr != c && find_place_b(*b, c) > 0)
			ft_rrr(a, b, 0);
		while ((*a)->nbr != c)
			ft_rra(a, 0);
		while (find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b);
	}
	else
	{
		while ((*b)->nbr != c && find_place_a(*a, c) > 0)
			ft_rrr(a, b, 0);
		while ((*b)->nbr != c)
			ft_rrb(b, 0);
		//fprintf(stderr, "find_place_a(*a, c): %i\n", find_place_a(*a, c));
		while (find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		ft_pa(a, b);
	}
	return (-1);
}

int	ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	//fprintf(stderr, "apply_rarrb\n");
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			ft_ra(a);
		while (find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b);
	}
	else
	{
		while (find_place_a(*a, c) > 0)
			ft_ra(a);
		while ((*b)->nbr != c)
			ft_rrb(b, 0);
		ft_pa(a, b);
	}
	return (-1);
}

int	ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	//fprintf(stderr, "apply_rrarb\n");
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			ft_rra(a, 0);
		while (find_place_b(*b, c) > 0)
			ft_rb(b);
		ft_pb(a, b);
	}
	else
	{
		while (find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		while ((*b)->nbr != c)
			ft_rb(b);
		ft_pa(a, b);
	}
	return (-1);
}
