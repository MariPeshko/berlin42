/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_dup_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 00:53:29 by mpeshko           #+#    #+#             */
/*   Updated: 2024/07/09 13:43:29 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// It checks if there are duplicates on the stack.
int	dup_search(t_stack *a)
{
	t_stack	*compare;

	if (!a)
		return (1);
	compare = a->next;
	while (a->next != NULL)
	{
		while (compare != NULL)
		{
			if (compare->nbr == a->nbr)
				return (1);
			compare = compare->next;
		}
		a = a->next;
		compare = a->next;
	}
	return (0);
}
