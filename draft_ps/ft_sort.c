#include "./push_swap.h"

void ft_sort(n_stack **stack_a)
{
    n_stack *stack_b;

    stack_b = NULL;
    if (ft_lstsize(*stack_a) == 2)
    {
        printf("Two numbers in a stack 'a'\n");
        ft_sa(stack_a);
    }
}