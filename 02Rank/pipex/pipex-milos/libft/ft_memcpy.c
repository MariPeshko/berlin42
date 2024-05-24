/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:45:18 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/17 12:27:52 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (src == (void *)0 && dest == (void *)0)
		return (dest);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*src = "ABCDEFGH";
	char	dst[8];

	ft_memcpy(dst, src, 8);
	printf("Dst has: %s\n", dst);
}
*/
