/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:23:17 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/21 21:20:28 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (small[j] == '\0') 
		return ((char *)big);
	while (big[i] && (i < len))
	{
		while (big[i + j] == small[j] && big[i + j] != '\0' && (i + j) < len)
			j++;
		if (small[j] == '\0')
			return ((char *)(big + i));
		i++;
		j = 0;
	}
	return (0);
}
/*int	main(void)
{
	const char	largestring[] = "42 1337 petwork 2021 piscine Benguerir";
	const char	smallstring[] = "piscine";
	char		*ptr;

	ptr = ft_strnstr(largestring, smallstring, 10);
	printf("The large string:\n%s\nThe small string:\n%s\n", largestring,
		smallstring);
	printf("Result of ft_strnstr function:\n%s\n", ptr);
	return (0);
}*/