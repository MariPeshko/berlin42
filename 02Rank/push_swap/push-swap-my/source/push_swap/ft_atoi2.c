/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:57:19 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/11 20:04:18 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

//Here an error message is being printed out
static void	ft_error_atoi(void)
{
	write (2, "Error\n", 6);
	exit(127);
}

static void	wrong_format(t_stack **my_node)
{
	ft_free(my_node);
	ft_error_atoi();
}

int	ft_check_int(long long int integer)
{
	if ((integer) > 2147483647 || (integer) < -2147483648)
	{
		ft_error_atoi();
		return (1);
	}
	else
		return (0);
}

// The function check the sign of the number,
// check if it is a digit, and then transform character(s)
// to integer. In the end it checks if it's a valid integer.
int	ft_atoi2(const char *str, t_stack **my_node)
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
			wrong_format(my_node);
		result = result * 10;
		result = result + (*str - '0');
		str++;
	}
	ft_check_int(result * sign);
	return (result * sign);
}

// int	main(void)
// {
// 	const char *a = "-+0013";
// 	ft_atoi2(a);
// 	return(0);
// }
