#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// # include "../libft/libft.h"

typedef struct stack
{
    int nbr;
    struct stack *next;
} n_stack;

int ft_checksort(n_stack **stack);

void ft_sort(n_stack **stack_a);

#endif