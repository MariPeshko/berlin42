/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:20:36 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/20 21:20:36 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (8);
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (8);
	else
		return (0);
}
/*int	main(void)
{
	char	c;
	int	result;

	c = 5;
	result = ft_isalnum(c);
	printf("When %c is passed, return (value is %d\n", c, result));

	c = 'l';
	result = ft_isalnum(c);
	printf("When %c is passed, return (value is %d\n", c, result));
	return (0);
}*/