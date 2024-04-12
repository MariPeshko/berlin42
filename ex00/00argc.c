#include <unistd.h> // write
#include <stdio.h>  // printf
#include <stdlib.h> // atoi

typedef struct stack
{
    int nbr;
    struct stack *next;
} n_stack;

// This function returns the last element of the stack.
n_stack *ft_lstlast(n_stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

// Function to add a new node to the stack from back side
void ft_add_back(n_stack **my_node, n_stack *stack_new)
{
    if (!my_node)
        return;
    if (!*my_node)
        *my_node = stack_new; // !!! function&
    else
        (ft_lstlast(*my_node))->next = stack_new;
}

// Creates new stack node with given number.
n_stack *ft_stack_new(int content)
{
    n_stack *new;

    new = malloc(sizeof(n_stack));
    if (!new)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    new->nbr = content;
    new->next = NULL;
    return (new);
}

// While arguments are valid, we start to add them
// into stack here one by one with while loop.
// Atoi takes the number and turn it into an integer
// value where we can make math operations.
// With stack new we create a new node for the current
// argument without linking it to list.
// We make linking stage in ft_add_back call.

void list_args(char **argv, n_stack **my_node)
{
    long nmb;

    nmb = 1;
    while (argv[nmb] != NULL)
    {
        ft_add_back(my_node, ft_stack_new(atoi(argv[nmb])));
        nmb++;
    }
}

int main(int argc, char **argv)
{
    char **strings;

    if (argc < 2)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    n_stack *my_node = (n_stack *)malloc(sizeof(n_stack));
    if (!my_node)
    {
        printf("Error: Memory allocation failed\n");
        return 1;
    }
    strings = argv;
    my_node->nbr = atoi(strings[1]);
    my_node->next = NULL;
    printf("The quantity of arguments: %d\n", (argc - 1));
    printf("The first argument is: %s\n", strings[1]);
    printf("The integer in the first node is: %d\n", my_node->nbr);

    list_args(argv, &my_node);

    free(my_node);
    return (0);
}