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

void ft_sa(n_stack **a);

int ft_checksort(n_stack *stack_a);

void ft_sort(n_stack **stack_a);

int ft_lstsize(n_stack *lst);

#endif