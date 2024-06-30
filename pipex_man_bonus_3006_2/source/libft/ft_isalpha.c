/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:29:44 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/21 21:33:58 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	else
		return (0);
}
/*int	main(void)
{
	char	c;
	c = 'A';
	printf("\nWhen uppercase character is passed: %d", ft_isalpha(c));
	c = 'z';
	printf("\nWhen lowercase character is passed: %d", ft_isalpha(c));
	c = 1;
	printf("\nWhen non-alphabetic character is passed: %d", ft_isalpha(c));
	printf("\n");
	return(0);
}*/