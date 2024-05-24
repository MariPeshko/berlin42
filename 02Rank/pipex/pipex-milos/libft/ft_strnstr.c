/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:46:45 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/17 12:30:06 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*hays;
	char	*need;

	i = 0;
	hays = (char *)big;
	need = (char *)little;
	if (*need == '\0')
		return (hays);
	while (hays[i] != '\0' && i < len)
	{
		j = 0;
		k = i;
		while (need[j] == hays[k] && need[j] != '\0')
		{
			j++;
			k++;
		}
		if (need[j] == '\0' && k <= len)
			return (&hays[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*haystack = "When a man goes on a hunt";
	char	*needle = "man";
	int	len = 8;

	printf("ft_strnstr says: %s\n", ft_strnstr(haystack, needle, len));
	return (0);
}
*/
