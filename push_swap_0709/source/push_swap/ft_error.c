/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:28:02 by mpeshko           #+#    #+#             */
/*   Updated: 2024/07/09 18:33:08 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

void	error_exit(int err_number)
{
	write(2, "Error\n", 6);
	exit(err_number);
}

void	error_mix_exit(int err_number)
{
	write(2, "Error\n", 6);
	exit(err_number);
}

void	error_dup_exit(int err_number)
{
	write(2, "Error\n", 6);
	exit(err_number);
}

// Malloc error
void	error_mall_exit(int err_number)
{
	write(2, "Error\n", 6);
	exit(err_number);
}

// Is there mix of argument and strings and any string contains not a digit or
// one '-' or one '+'.
// This functions checks if input contains strings with spaces.
// For example, the program doesn' work with such input '-3 "-66 " -44'
void	mix_str_int(char *argv, t_stack **a)
{
	int	i;

	i = 0;
	if (argv[i] == '\0')
	{
		free_stack(a);
		error_mix_exit(6);
	}
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]) || argv[i] == '-' || argv[i] == '+')
			i++;
		else
		{
			free_stack(a);
			error_mix_exit(3);
		}
	}
}
