/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:23:43 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/20 22:48:54 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c <= 122 && c >= 97)
	{
		c = c - 32;
		return (c);
	}
	else
		return (c);
}
/*int	main(void)
{
	char	c;

	c = 'm';
	printf("%c -> %c", c, toupper(c));
	c = 'D';
	printf("\n%c -> %c", c, toupper(c));
	c = '9';
	printf("\n%c -> %c\n", c, toupper(c));
	return (0);
}*/