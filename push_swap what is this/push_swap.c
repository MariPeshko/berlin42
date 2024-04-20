#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#include <stdio.h>

typedef	struct	stack
{
	void	*content;
	struct	stack	*next;
}		n_stack;

int	main (int argc, char **argv)
{
	n_list	*a;

	1. check_input and handle en error if the input isn't valid
	// check maximum integer, check if it is interger
	//in case of error: a doesn't exist or
	//arguments are not integers or no arguments

	2. A function that lists arguments. Creating a stack 'a',
	linked list: functions ft_lstadd_back and ft_lstnew
	and special ft_atoi (transforming a string into integers)

	if (!a)
	{
		free(a);
	}
	
// This function checks if the stack is sorted.

/* This function sorts the stack_a if there are more 
// than 2 elements in the stack_a.
// And finally it makes final sort in stack_a after
// all values pushed to stack_b, sorted and pushed
// back to stack_a. */

// This function frees the stack.
	free(a); // freeing all list
	return (0);
}
