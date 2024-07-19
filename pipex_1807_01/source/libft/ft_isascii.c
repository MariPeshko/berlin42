/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:20:28 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/20 21:20:28 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*int	main(void)
{
	int c;
	c = 'A';
	printf("\n%d - if it is a alphanumerical ASCII character", ft_isascii(c));

	c = 0x80;
	printf("\n%d - if it is not an ASCII character", ft_isascii(c));

	c = 127;
	printf("\n%d - if it is a non-alphanumerical ASCII character\n",
		ft_isascii(c));
	return (0);
}*/
