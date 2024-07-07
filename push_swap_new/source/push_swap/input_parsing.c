/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:12:26 by mpeshko           #+#    #+#             */
/*   Updated: 2024/07/04 17:26:59 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../libft/libft.h"

// The functions checks every characters from input. It displays "Error" in
// if the character if not a digit, SPACE ('32'), '-' or'+'.
int is_onlydigit(char **argv)
{
	int h;

	h = 0;
	while (argv[1][h] != '\0')
	{
		if (argv[1][h] == 32 || argv[1][h] == 45 || argv[1][h] == 43 || ft_isdigit(argv[1][h]))
			h++;
		else if (!ft_isdigit(argv[1][h]))
			return (0);
	}
	return (1);
}

// The function serves in case of only one argument as input.
// It check if the input contains only valid character.
// Then it uses ft_split to divide it to an array of strings.
// In a loop it creates a linked list 'a', that is refer to 'stack a'.
// In the end it frees the arrays if string and returns stack 'a'.
t_stack *one_arg(char **argv)
{
	t_stack *a;
	t_stack *node;
	char **strings;
	int i;
	int j;

	a = NULL;
	i = 0;
	if (!is_onlydigit(argv))
		error_exit(2);
	strings = ft_split(argv[1], 32);
	while (strings[i])
	{
		j = ft_atoi2(strings[i], &a);
		node = node_birth(j);
		stack_birth(&a, node);
		i++;
	}
	free_str_arr(strings);
	free(strings);
	return (a);
}

// Creating a stack if it does not exist.
// Appending a new node to the end of the existing node.
void stack_birth(t_stack **lst, t_stack *node)
{
	// if (!lst)
	// 	return ;
	if (!*lst)
		*lst = node;
	else
		(ft_lstlast(*lst))->next = node;
}

t_stack *node_birth(int content)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	if (!node)
		error_mall_exit(5);
	node->nbr = content;
	node->next = NULL;
	return (node);
}

// Returns stack 'a' on success. If there were no only digits, or
// the number was out of range of integer, then it
// frees allocated memory and displays "Error".
t_stack *input_into_stack(int argc, char **argv)
{
	t_stack *a;
	t_stack *node;
	int i;
	int j;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		mix_str_int(argv[i], &a);
		j = ft_atoi2(argv[i], &a);
		node = node_birth(j);
		stack_birth(&a, node);
		i++;
	}
	return (a);
}
