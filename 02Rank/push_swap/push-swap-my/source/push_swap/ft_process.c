/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:12:26 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/11 20:19:18 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// This function works and sorts the stacks
// in case of they are passed in between quotation
// marks. In this scenario, this function takes the
// string, and splits the numbers in order to create
// seperated integer number.
t_stack	*ft_sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi2(tmp[i], &a);
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

// Function to add a new node to the a from back side
void	ft_add_back(t_stack **my_node, t_stack *stack_new)
{
	if (!my_node)
		return ;
	if (!*my_node)
		*my_node = stack_new;
	else
		(ft_lstlast(*my_node))->next = stack_new;
}

// Creates new node with a given number.
t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		ft_error();
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
t_stack	*ft_procces(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	a = NULL;
	i = 1;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi2(argv[i], &a);
			ft_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	return (a);
}
