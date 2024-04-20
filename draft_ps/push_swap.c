#include <unistd.h> // write
#include <stdio.h>  // printf
#include <stdlib.h> // atoi

#include "./push_swap.h"

// This function frees the a.
void ft_free(n_stack **lst)
{
    n_stack *tmp;

    if (!lst)
        return;
    while (*lst)
    {
        tmp = (*lst)->next;
        (*lst)->nbr = 0;
        free(*lst);
        *lst = tmp;
    }
}

// This function returns the last element of the a.
n_stack *ft_lstlast(n_stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

// Function to add a new node to the a from back side
void ft_add_back(n_stack **my_node, n_stack *stack_new)
{
    if (!my_node)
        return;
    if (!*my_node)
    {
        *my_node = stack_new;
    }
    else
    {
        (ft_lstlast(*my_node))->next = stack_new;
    }
}

// Creates new a node with given number.
n_stack *ft_stack_new(int content)
{
    n_stack *new;

    new = malloc(sizeof(n_stack));
    if (!new)
    {
        write(1, "Error\n", 6);
        exit(1);
    }
    new->nbr = content;
    new->next = NULL;
    return (new);
}

// While arguments are valid, we start to add them
// into a here one by one with while loop.
// Atoi takes the number and turn it into an integer
// value where we can make math operations.
// With a new we create a new node for the current
// argument without linking it to list.
// We make linking stage in ft_add_back call.

n_stack *ft_procces(int argc, char **argv)
{
    n_stack *a;

    int i;
    int j;

    a = NULL;
    i = 1;
    if (argc < 2)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    // if (argc == 2)
    else
    {
        while (i < argc)
        {
            j = atoi(argv[i]);
            ft_add_back(&a, ft_stack_new(j));
            i++;
        }
    }
    return (a);
}

int main(int argc, char **argv)
{
    int i;
    n_stack *a;
    int check;

    a = ft_procces(argc, argv);

    if (a == NULL)
        printf("Linked list is empty");

    n_stack *ptr = NULL;
    ptr = a;
    i = 1;
    while (ptr != NULL)
    {
        printf("%d node is %d\n", i, ptr->nbr);
        ptr = ptr->next;
        i++;
    }

    check = ft_checksort(a);
    if (check == 0)
        printf("Numbers are sorted!\n");
    if (check == 2)
        printf("There is only 1 number\n");
    if (check == 1)
        printf("Oh no! Numbers are not sorted\n");

    ft_sort(&a);

    check = ft_checksort(a);
    if (check == 0)
        printf("Numbers are sorted!\n");
    if (check == 2)
        printf("There is only 1 number\n");
    if (check == 1)
        printf("Oh no! Numbers are not sorted\n");

    ptr = a;
    i = 1;
    while (ptr != NULL)
    {
        printf("%d node is %d\n", i, ptr->nbr);
        ptr = ptr->next;
        i++;
    }
    ft_free(&ptr);
    ft_free(&a);
    
    a = NULL;
    ptr = NULL;
    return (0);
}