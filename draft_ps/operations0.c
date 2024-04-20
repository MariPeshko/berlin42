#include "./push_swap.h"

// sa (swap a) : swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements).

void ft_sa(n_stack **a)
{
    n_stack *tmp;

    if (!*a || !((*a)->next))
        return;

    tmp = *a;
    *a = (*a)->next;
    tmp->next = (*a)->next;
    (*a)->next = tmp;

    write(1, "sa\n", 3);
}