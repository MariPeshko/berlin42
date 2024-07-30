/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:23:23 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/20 21:23:23 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
/*int	main(void)
{
	const char s[10] = "ABCDEFGAB";
	int c;
	char *frsoccurence;

	c = 'A';
	printf("Original string: %s\n", s);
	frsoccurence = ft_strrchr(s, c);
	printf("Pointer to the last occurence of %c is = %s\n", c, frsoccurence);
	printf("Original string: %s\n", s);
	return (0);
}*/