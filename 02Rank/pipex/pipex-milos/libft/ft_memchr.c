/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:45:02 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/17 12:30:19 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*str == (unsigned char)c)
			return ((void *) str);
		i++;
		str++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	int	c = 97;
	int	size = 8;
	char	*str = "character";

	printf("or_memchr found '%s' in %s\n", \
	(unsigned char *)memchr(str, c, size), str);
	printf("ft_memchr found '%s' in %s\n", \
	(unsigned char *)ft_memchr(str, c, size), str);
	return (0);
}
*/
