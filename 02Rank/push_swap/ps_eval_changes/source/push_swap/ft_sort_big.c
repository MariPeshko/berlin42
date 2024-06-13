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

// This function sorts and pushs stacks until 3 members left behind.
// It finds the 'cheapest' number.
// ft_rotate_type_ab function calculates and decides which rotation
// combination is best to use to sort the stack.
void	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	while (ft_lstsize(*stack_a) > 3 && !ft_checksort(*stack_a))
	{
		tmp = *stack_a;
		i = ft_rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(*stack_a, *stack_b, tmp->nbr))
				i = ft_apply_rarb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == ft_case_rrarrb(*stack_a, *stack_b, tmp->nbr))
				i = ft_apply_rrarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == ft_case_rarrb(*stack_a, *stack_b, tmp->nbr))
				i = ft_apply_rarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == ft_case_rrarb(*stack_a, *stack_b, tmp->nbr))
				i = ft_apply_rrarb(stack_a, stack_b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

// The algorithm starts with pushing two numbers from the top of
// the STACK_A to the STACK_B without checking anything.
// Then one by one it pushes all the elements in stack_a to the stack_b,
// until only three elements are left in stack_a. While pushing, it makes
// sure if the stack_b is sorted. When three elements are left, it calls
// the ft_sort_three function to sort left over elements in stack_a.
t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !ft_checksort(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !ft_checksort(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !ft_checksort(*stack_a))
		ft_sort_b_till_3(stack_a, &stack_b);
	if (!ft_checksort(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

// This function is pushing back the elements from stack_b
// to stack_a until stack_b is empty.
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = ft_rotate_type_ba(*stack_a, *stack_b);
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
	return (stack_a);
}

// This function sorts the stack_a if there are more
// than 2 elements in the stack_a.
// And finally it makes final sort in stack_a after
// all values pushed to stack_b, sorted and pushed
// back to stack_a. Because, even the stack_a is
// sorted at the end, the minimum number have to
// at the top of the stack_a. So, it simply brings
// the smallest number of the stack_a to the top.
void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = ft_find_index(*stack_a, ft_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				ft_ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				ft_rra(stack_a, 0);
		}
	}
	ft_free(&stack_b);
	free(stack_b);
	stack_b = NULL;
}
