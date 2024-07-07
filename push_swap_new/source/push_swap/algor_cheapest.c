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

int alg_cheapest_ab(t_stack *a, t_stack *b, int *index)
{
	int i;
	int ind;
	int cost;
	t_stack *tmp;

	tmp = a;
	ind = 0;
	i = ft_case_rrarrb(a, b, a->nbr);
	//printf("ft_case_rrarrb(a, b, a->nbr): %i\n", i);
	cost = i;
	while (tmp)
	{
		//printf("nbr: %i\n", tmp->nbr);
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
