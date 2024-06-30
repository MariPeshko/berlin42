/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:22:29 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/20 21:22:29 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// locate first occurence of the character in a string.
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	else
		return (0);
}
/*int	main(void)
{
	const char s[10] = "ABCDEFGAB";
	int c;
	char *frsoccurence;

	c = 'A';
	printf("Original string: %s\n", s);
	frsoccurence = ft_strchr(s, c);
	printf("Pointer to the first occurence of %c is = %s\n", c, frsoccurence);
	printf("Original string: %s\n", s);
	return (0);
}*/