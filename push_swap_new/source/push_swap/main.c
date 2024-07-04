/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:12:37 by mpeshko           #+#    #+#             */
/*   Updated: 2024/07/04 17:29:25 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc == 1)
		exit (1);
	a = input_into_stack(argc, argv);
	if (!a || dup_search(a))
	{
		free_stack(&a);
		error_dup_exit();
	}
	if (!ft_checksort(a))
		ft_sort(&a);
	free_stack(&a);
	return (7);
}
