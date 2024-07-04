/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:12:26 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/13 20:12:08 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

static int	is_onlydigit(char **argv)
{
	int	h;

	h = 0;
	while (argv[1])
	{
		if (!ft_isdigit(argv[1][h]))
			ft_error();
		h++;
	}
	return (0);
}

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
	is_onlydigit(argv);
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

t_stack	*ft_procces(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	t_stack *new;

	a = NULL;
	i = 1;
	if (argc < 2)
		exit (1);
	if (argc == 2)
		a = ft_sub_process(argv);
	else
	{
		while (i < argc)
		{
			mix_str_int(argv[i], &a);
			j = ft_atoi2(argv[i], &a);
			new = ft_stack_new(j);
			ft_add_back(&a, new);
			i++;
		}
	}
	return (a);
}
