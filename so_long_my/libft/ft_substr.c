/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:55:59 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/20 21:47:32 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	while (s[i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*int	main (void)
{
	char	str[] = "Hello, World!";
	char	*substring = ft_substr(str, 7, 5);
	printf("\nThe string:\n%s\nThe substring:\n%s\n\n", str, substring);

	char	*empty_substring = ft_substr(NULL, 0, 10);
	printf("\nThe string:\n%s\nThe empty_substring:\n%s\n\n", str,
		empty_substring);
	return (0);
}*/