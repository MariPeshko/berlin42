#include <unistd.h> // write
#include <stdio.h>  // printf
#include <stdlib.h> // atoi

#include "./push_swap.h"

// This function checks if the stack is sorted.
int ft_checksort(n_stack **stack)
{
    n_stack *tmp1;
    n_stack *tmp2;

    tmp1 = *stack;
    printf("tmp1->nbr: %d\n", tmp1->nbr);

    if (!stack)
        return (1);
    if (tmp1->next == NULL)
        return (2);
    tmp2 = tmp1->next;

    while (tmp1->next != NULL)
    {
        printf("tmp2->nbr: %d\n", tmp2->nbr);
        if (tmp1->nbr > tmp2->nbr)
            return (1);
        else
        {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }
    return (0);
}