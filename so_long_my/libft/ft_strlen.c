/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:23:01 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/21 21:36:07 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*int	main(void)
{
	char	a[20] = "Program";
	char	b[20] = {'P', 'r', 'o', 'g', 'r', 'a', 'm', '\0'};

	printf("Length of string a = %zu \n", ft_strlen(a));
	printf("Length of string b = %zu \n", ft_strlen(b));
	return (0);
}*/