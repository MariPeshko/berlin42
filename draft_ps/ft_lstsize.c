/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:55:48 by mpeshko           #+#    #+#             */
/*   Updated: 2024/04/20 00:42:02 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include "./push_swap.h"

// Calculates and returns the number of nodes in a given linked list ‘lst’.

int ft_lstsize(n_stack *lst)
{
	n_stack *tmp;
	int i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}