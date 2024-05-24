#include "../../includes/push_swap.h"

// pb (push b) : take the first element at the top of a and put it
// at the top of b. Do nothing if a is empty.
void	ft_pb(n_stack **stack_a, n_stack **stack_b, int j)
{
	n_stack *tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (j == 0)
		write(1, "pb\n", 3);
}

// rb (rotate b) : shift up all elements of stack b by 1.
// The first element becomes the last one.
void	ft_rb(n_stack **b, int j)
{
	n_stack *tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

void ft_rr(n_stack **a, n_stack **b, int j)
{
	n_stack *tmp;

	if (!*a || !(*a)->next || (!*b || !(*b)->next))
		return;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rr\n", 3);
}