/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:20:22 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/20 21:20:22 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	else
		return (0);
}
/*int	main(void)
{
	char c;

	c = 'A';
	printf("\nWhen alphabetic character is passed: %d", ft_isdigit(c));

	c = '!';
	printf("\nWhen non-digit is passed: %d", ft_isdigit(c));

	c = 0;
	printf("\nWhen digit is passed: %d", ft_isdigit(c));
	printf("\n");
	return (0);
}*/