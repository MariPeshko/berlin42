/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:49:32 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/30 17:08:43 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*ref2nxt;

	if (!(*lst))
		return ;
	ref2nxt = *lst;
	while (*lst)
	{
		ref2nxt = (*lst)->next;
		ft_lstdelone(lst);
		*lst = ref2nxt;
	}
	*lst = NULL;
	return ;
}
