/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:44:49 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/30 13:59:24 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	l;
	int		minus;

	l = 0;
	minus = 1;
	if (ft_isintmacro(nptr) == -1)
		return (INT_MIN);
	else if (ft_isintmacro(nptr) == 1)
		return (INT_MAX);
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			minus = -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		l += *nptr - 48;
		l *= 10;
		nptr++;
	}
	return (l / 10 * minus);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*str = "  \n\t\r\v\f -2147483648";

	printf("ft_atoi found in the string is %d\n", ft_atoi(str));
	printf("or_atoi found in the string is %d\n", atoi(str));
}
*/
