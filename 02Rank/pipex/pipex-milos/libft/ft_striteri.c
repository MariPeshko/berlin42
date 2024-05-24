/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:04:01 by mitadic           #+#    #+#             */
/*   Updated: 2023/11/24 18:04:05 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s != 0)
	{
		i++;
		s++;
	}
	while (i > 0)
	{
		s--;
		i--;
		f(i, s);
	}
	return ;
}

/*
void	f(unsigned int ind, char *str)
{
	if (*str == 'e' && ind % 2 == 0)
		*str = 'r';
	return ;
}


#include <stdio.h>
int	main(void)
{
	char	src[] = "Hematomes The Size Of A Globe";

	ft_striteri(src, f);
	printf("changed src says %s\n", src);
}
*/
