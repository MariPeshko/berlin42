/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:47:00 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/17 12:28:41 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	if (destlen >= size)
		return (size + srclen);
	if (size > srclen + destlen)
		ft_memcpy(dest + destlen, src, srclen + 1);
	else
	{
		ft_memcpy(dest + destlen, src, size - destlen - 1);
		dest[size - 1] = '\0';
	}
	return (destlen + srclen);
}
/*
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	size_t	i = 6;
	char	dest[20];
	char	*str1 = "ABCDEFGH";
	char	*str2 = "12345678";
	
	strcpy(dest, str1);
	printf("or_strlcat has returned %lu, has made %s w/ size %lu\n",\
			strlcat(dest, str2, i), dest, i);
	dest[8] = '\0';
	printf("ft_strlcat has returned %lu, has made %s w/ size %lu\n",\
			ft_strlcat(dest, str2, i), dest, i);
	return (0);
}
*/
// compile like this:
//	cc ft_strlcat.c ft_memcpy.c ft_strlen.c -lbsd
