/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:22:51 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/21 21:35:56 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	lensrc;
	size_t	lendst;
	size_t	total_len;
	size_t	i;
	size_t	j;

	i = 0;
	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	j = lendst;
	if (n > lendst)
		total_len = lendst + lensrc;
	else
		total_len = lensrc + n;
	while (src[i] && j + 1 < n)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (total_len);
}
/*int	main(void)
{
	char	dst[20] = "Berlin 42 ";
	char	src[] = "is fun!";

	printf("Source is: %s\nDestination is: %s\n", src, dst);
	printf("Ft_strlcat returns a size_t: %li\n", ft_strlcat(dst, src, 18));
	printf("Destination after ft_strlcat: %s\n", dst);
	return (0);
}*/
