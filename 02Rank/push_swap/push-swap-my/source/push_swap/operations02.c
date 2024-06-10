/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:29:01 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/10 19:29:04 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// sb (swap b) : swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements).
void ft_sb(n_stack **b, int j)
{
    if (!*b || !(*b)->next)
        return;
    n_stack *tmp;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = (*b)->next;
    (*b)->next = tmp;
    if (j == 0)
        write(1, "sb\n", 3);
}

// rra (reverse rotate a) : shift down all elements of stack a by 1.
// The last element becomes the first one.
void ft_rra(n_stack **a, int j)
{
    n_stack *tmp;
    int i;

    i = 0;
    if (!*a || !(*a)->next)
        return;
    tmp = *a;
    while ((*a)->next != NULL)
    {
        (*a) = (*a)->next;
        i++;
    }
    (*a)->next = tmp;
    while (i > 1)
    {
        tmp = tmp->next;
        i--;
    }
    tmp->next = NULL;

    if (j == 0)
        write(1, "rra\n", 4);
}

// rrb (reverse rotate b) : shift down all elements of stack a by 1.
// The last element becomes the first one.
void ft_rrb(n_stack **b, int j)
{
    n_stack *tmp;
    int i;

    i = 0;
    if (!*b || !(*b)->next)
        return;
    tmp = *b;
    while ((*b)->next != NULL)
    {
        (*b) = (*b)->next;
        i++;
    }
    (*b)->next = tmp;
    while (i > 1)
    {
        tmp = tmp->next;
        i--;
    }
    tmp->next = NULL;
    if (j == 0)
        write(1, "rrb\n", 4);
}

// Second part of the rrr function
void ft_rrr_sub(n_stack **b, int j)
{
    n_stack *tmp;
    int i;

    i = 0;
    tmp = *b;
    while ((*b)->next)
    {
        i++;
        *b = (*b)->next;
    }
    (*b)->next = tmp;
    while (i > 1)
    {
        tmp = tmp->next;
        i--;
    }
    tmp->next = NULL;
    if (j == 0)
        write(1, "rrr\n", 4);
}

// rrr : rra and rrb at the same time.
void ft_rrr(n_stack **a, n_stack **b, int j)
{
    n_stack *tmp;
    int i;

    if (!*a || !((*a)->next) || !*b || !((*b)->next))
        return;
    i = 0;
    tmp = *a;
    while ((*a)->next)
    {
        i++;
        *a = (*a)->next;
    }
    (*a)->next = tmp;
    while (i > 1)
    {
        tmp = tmp->next;
        i--;
    }
    tmp->next = NULL;
    ft_rrr_sub(b, j);
}
