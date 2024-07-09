/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:21:08 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/20 21:52:41 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*destcpy;
	char	*srccpy;
	size_t	i;

	destcpy = (char *)dest;
	srccpy = (char *)src;
	i = 0;
	if (dest == 0 && src == 0)
		return (dest);
	while (i < n)
	{
		destcpy[i] = srccpy[i];
		i++;
	}
	return (destcpy);
}
/*int	main(void)
{
	char	src[40] = "Source";
	char	dest[40] = "Destin";

	printf("Destination before ft_memcpy: %s\n", dest);
	ft_memcpy(dest, src, 3);
	printf("Destination after ft_memcpy: %s\n", dest);
	return (0);
}*/