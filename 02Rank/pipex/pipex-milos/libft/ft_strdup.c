/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:44:41 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/17 12:31:09 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*src;
	char	*dst;
	int		i;

	src = (char *)s;
	dst = malloc(sizeof(char) * ft_strlen(src) + 1);
	i = 0;
	if (dst != NULL)
	{
		while (src[i] != 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	*str = "This is my string";
	printf("dest string @ft_strdup says: %s\n", ft_strdup(str));
	printf("dest string @strdup (original) says: %s\n", strdup(str));
}
*/
