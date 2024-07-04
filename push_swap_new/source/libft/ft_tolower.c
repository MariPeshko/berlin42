/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:23:36 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/20 21:54:45 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c <= 90 && c >= 65)
	{
		c = c - 'A' + 'a';
		return (c);
	}
	else
		return (c);
}
/*int	main(void)
{
	char	c;

	c = 'm';
	printf("%c -> %c", c, ft_tolower(c));
	c = 'D';
	printf("\n%c -> %c", c, ft_tolower(c));
	c = '9';
	printf("\n%c -> %c\n", c, ft_tolower(c));
	return (0);
}*/