/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:47:59 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/15 15:48:00 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head_cpy;

	if (!new)
		return ;
	if (*lst == (void *)0)
	{
		*lst = new;
		return ;
	}
	head_cpy = *lst;
	while (head_cpy->next)
		head_cpy = head_cpy->next;
	head_cpy->next = new;
	return ;
}
