/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:19:08 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/21 21:34:23 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr < 1)
		len = 1;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	number;

	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		number = n * -1;
		str[0] = '-';
	}
	else
		number = n;
	while (number > 0 && len >= 0)
	{
		str[len] = 48 + (number % 10);
		number = number / 10;
		len--;
	}
	return (str);
}
/*int	main(void)
{
	printf("\n12345\n%s\n\n", ft_itoa(12345));
	printf("-456\n%s\n\n", ft_itoa(-456));
	printf("0\n%s\n\n", ft_itoa(0));
	printf("2147483647\n%s\n\n", ft_itoa(2147483647));
	printf("-2147483648\n%s\n\n", ft_itoa(-2147483648));
	return (0);
}*/