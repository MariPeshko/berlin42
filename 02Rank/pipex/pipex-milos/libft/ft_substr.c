/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:13:48 by mitadic           #+#    #+#             */
/*   Updated: 2023/11/20 17:22:47 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*src;
	char			*dest;
	unsigned int	i;
	unsigned int	srclen;

	src = (char *)s;
	srclen = ft_strlen(src);
	i = 0;
	while (i < len && !(start >= srclen) && src[start + i] != 0)
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest || !s)
		return (NULL);
	i = 0;
	while (i < len && !(start >= srclen) && src[start + i] != 0)
	{
		dest[i] = src[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
