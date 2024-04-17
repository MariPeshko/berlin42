#include <unistd.h> // write
#include <stdio.h>  // printf
#include <stdlib.h> // atoi

typedef struct stack
{
    int nbr;
    struct stack *next;
} n_stack;

// This function frees the stack.
void	ft_free(n_stack **lst)
{
	n_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = tmp;
	}
}

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
    {
        printf("I'm here ft_add_back in if (!*my_node)\n");
        *my_node = stack_new;
    }
    else
    {
        (ft_lstlast(*my_node))->next = stack_new;
    }
}

// Creates new stack node with given number.
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
// into stack here one by one with while loop.
// Atoi takes the number and turn it into an integer
// value where we can make math operations.
// With stack new we create a new node for the current
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
            printf("\n%d loop in ft_procces\n", i);
            j = atoi(argv[i]);
            printf("j = %d\n\n", j);
            ft_add_back(&a, ft_stack_new(j));
            i++;
        }
    }
    return (a);
}

int main(int argc, char **argv)
{
    int i;

    n_stack *my_node;

    /*{        printf("Error: Memory allocation failed\n");
        return 1;    }*/
    // printf("The quantity of arguments: %d\n", (argc - 1));
    // printf("The first argument is: %s\n", strings[1]);
    // printf("The integer in the first node is: %d\n", my_node->nbr);

    my_node = ft_procces(argc, argv);

    if (my_node == NULL)
        printf("Linked list is empty");
    n_stack *ptr = NULL;
    ptr = my_node;
    i = 1;
    while (ptr != NULL)
    {
        printf("%d node is %d\n", i, ptr->nbr);
        ptr = ptr->next;
        i++;
    }

    ft_free(&my_node);
    
    free(ptr);
    my_node = NULL;
    ptr = NULL;
    return (0);
}