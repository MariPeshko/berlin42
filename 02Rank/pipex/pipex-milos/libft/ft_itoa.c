/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:38:50 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/17 12:32:32 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*assign(char *res, int i, long n)
{
	res[i] = '\0';
	if (n == 0)
	{
		res[i] = '\0';
		res[i - 1] = 48;
	}
	else if (n < 0)
	{
		n *= -1;
		while (--i > 0)
		{
			res[i] = n % 10 + 48;
			n /= 10;
		}
		res[i] = '-';
	}
	else
	{
		while (--i >= 0)
		{
			res[i] = n % 10 + 48;
			n /= 10;
		}
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		i;
	long	cpy;
	char	*res;

	cpy = n;
	i = 0;
	if (cpy <= 0)
	{
		cpy *= -1;
		i = 1;
	}
	while (cpy > 0)
	{
		cpy /= 10;
		i++;
	}
	res = malloc(i * sizeof(char) + 1);
	if (!res)
		return (NULL);
	res = assign(res, i, n);
	return (res);
}

/*
#include <stdio.h>
int	main(void)
{
	int	i = 0;
	int	j = -2147483648;
	int	k = 10;

	printf("int %i as str is:[ctrl]%s[ctrl]\n", i, ft_itoa(i));
	printf("int %i as str is:[ctrl]%s[ctrl]\n", j, ft_itoa(j));
	printf("int %i as str is:[ctrl]%s[ctrl]\n", k, ft_itoa(k));
}
*/
