/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:28:02 by mpeshko           #+#    #+#             */
/*   Updated: 2024/07/04 17:24:45 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(2);
}

void	error_mix_exit(void)
{
	write(2, "Error\n", 6);
	exit(3);
}

void	error_dup_exit(void)
{
	write(2, "Error\n", 6);
	exit(4);
}

void	error_mall_exit(void)
{
	write(2, "Error\n", 6);
	exit(5);
}

// Is there mix of argument and strings and any string contains not a digit or
// one '-' or one '+'.
// This functions checks if input contains strings with spaces.
// For example, the program doesn' work with such input '-3 "-66 " -44'
void	mix_str_int(char *argv, t_stack **a)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]) || argv[i] == '-' || argv[i] == '+')
			i++;
		else
		{
			free_stack(a);
			error_mix_exit();
		}
	}
	// while (argv[i])
	// {
	// 	if (ft_strchr(&argv[i], ' ') || ft_strchr(&argv[i], 47)
	// 	|| ft_strchr(&argv[i], 34))
	// 	{
	// 		ft_free(a);
	// 		ft_error_mix();
	// 	}
	// 	i++;
	// }
}
