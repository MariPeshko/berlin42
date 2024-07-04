/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:12:37 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/13 16:12:40 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_procces(argc, argv);
	if (!a || dup_search(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksort(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}
