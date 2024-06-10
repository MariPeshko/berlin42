/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:55:24 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/10 19:28:39 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// This function returns the last element of the stack.
n_stack	*ft_lstlast(n_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// This function finds and returns the smallest number
// in the given stack.
int	ft_min(n_stack *a)
{
	int	min;
	
	min = a->nbr;
	while(a)
	{
		if(min > a->nbr)
			min = a->nbr;
		a = a->next;
	}
	return (min);
}

// This function finds and returns the biggest number
// in the given stack.
int	ft_max(n_stack *a)
{
	int	max;
	
	max = a->nbr;
	while(a)
	{
		if(max < a->nbr)
			max = a->nbr;
		a = a->next;
	}
	return (max);
}