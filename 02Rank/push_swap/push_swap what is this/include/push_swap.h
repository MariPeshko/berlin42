#ifndef STACK_H
# define STACK_H

//# include "libft.h"
//# include "ft_printf.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef	struct	stack
{
	void	*content;
	struct	stack	*next;
}               n_stack;

// MAIN PUSH_SWAP
int	main (int argc, char **argv);

#endif