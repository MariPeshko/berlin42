/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstintpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:22:19 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/22 15:04:36 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// checking if !content is a bit silly, but can't check !(*content) w/o casting

int	ft_lstintpos(t_list *lst, int n)
{
	int	pos;

	pos = 0;
	if (!lst)
		return (-1);
	while (lst != NULL)
	{
		if (*(int *)lst->content == n)
			return (pos);
		lst = lst->next;
		pos++;
	}
	return (-1);
}
