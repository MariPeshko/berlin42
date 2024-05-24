/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:45:09 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/17 12:30:30 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ma1;
	unsigned char	*ma2;
	size_t			i;

	i = 0;
	if ((s1 == (void *)0 && s2 == (void *)0) || n == 0)
		return (0);
	ma1 = (unsigned char *)s1;
	ma2 = (unsigned char *)s2;
	while (i < (n - 1) && ma1[i] == ma2[i])
		i++;
	return (ma1[i] - ma2[i]);
}
