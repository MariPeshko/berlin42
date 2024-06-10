/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:28:47 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/10 19:28:48 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// sa (swap a) : swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements).
void ft_sa(n_stack **a, int j)
{
    n_stack *tmp;

    if (!*a || !((*a)->next))
        return;

    tmp = *a;
    *a = (*a)->next;
    tmp->next = (*a)->next;
    (*a)->next = tmp;
    if (j == 0)
    write(1, "sa\n", 3);
}

// pa (push a) : take the first element at the top of b and
// put it at the top of a. Do nothing if b is empty.
void ft_pa(n_stack **a, n_stack **b, int j)
{
    n_stack *tmp;

    if (!*b)
        return;
    tmp = *a;
    *a = *b;
    *b = (*b)->next;
    (*a)->next = tmp;
    if (j == 0)
        write(1, "pa\n", 3);
}

// ss : sa and sb at the same time.
void ft_ss(n_stack **a, n_stack **b, int j)
{
    n_stack *tmp;

    if (!*a || !((*a)->next) || !*b || !((*b)->next))
        return;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = (*a)->next;
    (*a)->next = tmp;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = (*b)->next;
    (*b)->next = tmp;
    if (j == 0)
        write(1, "ss\n", 3);
}

// ra (rotate a) : shift up all elements of stack a by 1.
// The first element becomes the last one.
/*
void ft_ra(n_stack **a, int j) // my
{
    n_stack *tmp;

    if (!*a || !(*a)->next)
        return;
    tmp = *a;
    *a = (*a)->next;
    ft_lstlast(*a)->next = tmp;
    tmp->next = NULL;
    if (j == 0)
        write(1, "ra\n", 3);
}
*/

void	ft_ra(n_stack **a, int j)
{
	n_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
    *a = ft_lstlast(*a);
    (*a)->next = tmp;
    *a = tmp->next;
	tmp->next = NULL;
    if (j == 0)
		write(1, "ra\n", 3);
}

