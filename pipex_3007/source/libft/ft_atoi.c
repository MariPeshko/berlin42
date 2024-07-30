/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 20:11:00 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/21 21:32:58 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
/*int	main(void)
{
	const char	*string;
	int	number;

	string = "    ---+--+1234ab567";
	printf("The string of characters is:\n%s\n", string);
	number = ft_atoi(string);
	printf("The result of atoi function is a number:\n%d\n", number);
	return (0);
}*/