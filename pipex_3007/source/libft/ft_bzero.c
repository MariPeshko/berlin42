/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:17:30 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/21 21:33:04 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*int	main(void)
{
	unsigned char	str[17] = "Hitchhiker";
	size_t			n;

	n = 3;
	printf("%s\n", str);
	ft_bzero(str + 7, n);
	printf("%s\n", str);
	return (0);
}*/