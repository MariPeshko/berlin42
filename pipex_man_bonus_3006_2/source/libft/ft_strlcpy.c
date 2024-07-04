/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:22:56 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/20 21:22:56 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src || !dest || size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*int	main(void)
{
	char dest[20] = "Kyiv";
	const char src[40] = "Berlin is the capital of Germany";
	size_t size;
	int num;

	size = 2;
	printf("Source before is: %s\nDestination before is: %s\n", src, dest);
	num = ft_strlcpy(dest, src, size);
	printf("Source after is: %s\nDestination after is: %s\n", src, dest);
	printf("Num returned: %d\n", num);
	return (0);
}*/