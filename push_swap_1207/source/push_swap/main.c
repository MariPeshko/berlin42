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

int main(int argc, char **argv)
{
	t_stack *a;

	if (argc == 1)
		exit(1);
	if (argc == 2)
		a = one_arg(argv);
	else
		a = input_into_stack(argc, argv);
	if (!a || dup_search(a))
	{
		free_stack(&a);
		error_dup_exit(4);
	}
	if (!check_sort(a))
	{
		if (ft_lstsize(a) == 2)
			ft_sa(&a);
		else
			sort_algorithm(&a);
	}
	free_stack(&a);
	return (0);
}
