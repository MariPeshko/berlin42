/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:05:21 by mitadic           #+#    #+#             */
/*   Updated: 2023/11/24 18:06:42 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[i] != 0)
		i++;
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[i] = '\0';
	while ((--i + 1) > 0)
		res[i] = f(i, s[i]);
	return (res);
}

/*
char	f(unsigned int ind, char c)
{
	if (ind % 2 == 0)
		c = ' ';
	return (c);
}

#include <stdio.h>
int	main(void)
{
	char	*src = "ThisIsAString";
	char	*dest;

	dest = ft_strmapi(src, f);
	printf("dest says: %s\n", dest);
}
*/
