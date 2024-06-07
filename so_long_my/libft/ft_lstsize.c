/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:55:48 by mpeshko           #+#    #+#             */
/*   Updated: 2024/04/09 19:03:03 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Calculates and returns the number of nodes in a given linked list ‘lst’.

int ft_lstsize(t_list *lst)
{
	t_list *tmp;
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
