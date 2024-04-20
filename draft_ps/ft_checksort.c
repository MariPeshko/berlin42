#include <unistd.h> // write
#include <stdio.h>  // printf
#include <stdlib.h> // atoi

#include "./push_swap.h"

// This function checks if the stack is sorted.
int ft_checksort(n_stack *stack_a)
{
    int i;

    if (stack_a->next == NULL)
        return (2);
    i = stack_a->nbr;
    while (stack_a)
    {
        if (i > stack_a->nbr)
            return (1);
        i = stack_a->nbr;
        stack_a = stack_a->next;
    }
    return (0);
}