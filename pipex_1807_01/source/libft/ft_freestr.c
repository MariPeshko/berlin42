/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:37:03 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/09 18:30:44 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// This function free the array of strings
void	ft_freestr(char **lst)
{
	int		i;
	char	*n1;

	i = 0;
	if (!lst)
		return ;
	while (lst[i] != NULL)
	{
		n1 = lst[i];
		i++;
		free(n1);
	}
	free(lst);
}
