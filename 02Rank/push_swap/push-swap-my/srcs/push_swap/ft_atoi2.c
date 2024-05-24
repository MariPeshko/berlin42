/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:57:19 by mpeshko           #+#    #+#             */
/*   Updated: 2024/05/13 20:59:27 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_check_int(long long int integer)
{
	if ((integer) > 2147483647 || (integer) < -2147483648)
	{
		ft_error();
		return (1);
	}
	else
		return (0);
}

// The function check the sign of the number,
// check if it is a digit, and then transform character(s)
// to integer. In the end it checks if it's a valid integer.
int	ft_atoi2(const char *str)
{
	int				sign;
	long long int	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			ft_error();
		result = result * 10;
		result = result + (*str - '0');
		str++;
	}
	ft_check_int(result * sign);
	return (result * sign);
}
