/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:21:23 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/21 21:34:46 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*strptr;
	size_t			i;

	i = 0;
	strptr = s;
	while (i < n)
	{
		strptr[i] = c;
		i++;
	}
	return (s);
}
/*int	main(void)
{
	char	str[20] = "Hitchhiker's guide";
	char	c;
	size_t	n;

	c = '#';
	n = 5;
	printf("Before ft_memset: %s\n", str);
	ft_memset(str, c, n);
	printf("After ft_memset:  %s\n", str);
	return (0);
}*/