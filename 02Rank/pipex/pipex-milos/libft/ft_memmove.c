/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:23:55 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/17 12:28:01 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (!src && !dest)
		return (dest);
	if (dest > src)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*
#include <stdio.h>
int	main(void)
{
	int	src1[] = {0, 1, 2, 3, 4, 5, 6, 7};
	int	dst1[8];
	char	*src2 = "ABCDEFGH";
	char	dst2[8];
	int	times;
	int	i;

	times = 8;
	i = 0;
	// int array test
	ft_memmove(dst1, src1, times);
	while (i < times)
	{
		printf("dst1 has: %i\n", dst1[i]);
		i++;
	}
	// char array test
	ft_memmove(dst2, src2, times);
	i = 0;
	while (i < times)
	{
		printf("dst2 has: %c\n", dst2[i]);
		i++;
	}
}
*/
