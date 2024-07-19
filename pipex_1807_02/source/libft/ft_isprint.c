/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:18:44 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/20 22:46:33 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (16384);
	else
		return (0);
}
/*int	main(void)
{
	char	c;

	c = 'S';
	printf("\nResult when a printable character %c is passed to isprint(): %d",
		c, ft_isprint(c));
	c = '\n';
	printf("\nResult when a control character is passed to isprint(): %d\n",
		ft_isprint(c));
	return (0);
}*/