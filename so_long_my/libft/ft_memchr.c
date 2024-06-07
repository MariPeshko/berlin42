/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:10:23 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/21 20:00:20 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*strtoreturn;

	strtoreturn = (unsigned char *) s;
	i = 0;
	while (n > i)
	{
		if (strtoreturn[i] == (unsigned char)c)
			return ((void *) &strtoreturn[i]);
		i++;
	}
	return (NULL);
}
/*int	main(void)
{
	const char	s[10] = "DCBABCDA";
	const char	s2[10] = "DCBDCBBCD";
	int			c;
	size_t		n;
	char		*new;
	char		*newnew;

	c = 'A';
	n = 5;
	printf("Original string #1: %s\nOriginal string #2: %s\n", s, s2);
	new = (void *)ft_memchr(s, c, n);
	return (0);
}*/