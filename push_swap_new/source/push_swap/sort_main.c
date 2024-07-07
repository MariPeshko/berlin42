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
	i = position_in_stack(*a, min_nbr(*a));

	if (i < ft_lstsize(*a) - i)
	{
		while ((*a)->nbr != min_nbr(*a))
			ft_ra(a);
	}
	else
	{
		while ((*a)->nbr != min_nbr(*a))
			ft_rra(a, 0);
	}
}

t_stack **sort_push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	t_stack *tmp;

	// printf("\npush from b\n");
	while (*stack_b)
	{
		tmp = *stack_b;
		// printf("tmp-nbr: %i\n", tmp->nbr);
		i = ft_rotate_type_ba(*stack_a, *stack_b);
		// і має бути нуль для випадку а - 2 3 4, b - 5
		// printf("i: %i\n", i);
		while (i >= 0)
		{
			if (i == ft_case_rarb_a(*stack_a, *stack_b, tmp->nbr))
				i = ft_apply_rarb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == ft_case_rarrb_a(*stack_a, *stack_b, tmp->nbr))
				i = ft_apply_rarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == ft_case_rrarrb_a(*stack_a, *stack_b, tmp->nbr))
				i = ft_apply_rrarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == ft_case_rrarb_a(*stack_a, *stack_b, tmp->nbr))
				i = ft_apply_rrarb(stack_a, stack_b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	// tmp = *stack_a;
	//  while(tmp)
	//  {
	//  	fprintf(stderr, "stack_a: %i\n", tmp->nbr);
	//  	tmp = tmp->next;
	//  }
	return (stack_a);
}

// ********IDEA: // && ft_lstsize(*stack_a) > 10
// Pushing all integers from tha stack 'a' to the stack 'b, till
// either three integers are left, or stack 'a' is sorted in
// ascending order. During each push, considering stack 'b' is
// sorted in descending order.
t_stack *sort_push_to_b(t_stack **a, t_stack **b)
{
	int cheapest;
	t_stack *tmp;
	int index;

	while (ft_lstsize(*a) > 3 && !check_sort(*a))
	{
		printf("sort_push_to_b. 1 while\n");
		tmp = *a;
		index = 0;

		// а що, якби alg_cheapest_ab повертав не лише кількість
		// операцій, а повертав би індекс необхідного числа.
		cheapest = alg_cheapest_ab(*a, *b, &index);
	
		while (cheapest >= 0)
		{
			if (cheapest == case_one(*a, *b, tmp->nbr))
				cheapest = do_case_one(a, b, tmp->nbr);
			else if (cheapest == ft_case_rarb(*a, *b, tmp->nbr))
				cheapest = ft_apply_rarb(a, b, tmp->nbr, 'a');
			else if (cheapest == ft_case_rrarrb(*a, *b, tmp->nbr))
				cheapest = ft_apply_rrarrb(a, b, tmp->nbr, 'a');
			else if (cheapest == ft_case_rarrb(*a, *b, tmp->nbr))
				cheapest = ft_apply_rarrb(a, b, tmp->nbr, 'a');
			else if (cheapest == ft_case_rrarb(*a, *b, tmp->nbr))
				cheapest = ft_apply_rrarb(a, b, tmp->nbr, 'a');
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
