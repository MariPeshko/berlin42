/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_struct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:21:30 by mpeshko           #+#    #+#             */
/*   Updated: 2024/07/21 17:42:56 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

static int	free_list(t_id_list **list)
{
	t_id_list	*tmp;

	if (!*list)
		return (-1);
	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	return(0);
}

void	free_struct(child_return **ch)
{
	fprintf(stderr, "free_list return %i\n", free_list(&(*ch)->list));
	free(*ch);
}

// Returns a pointer to the last node in a stack.
t_id_list	*ft_lstlast(t_id_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// Malloc error
void	error_mall_exit(int err_number)
{
	write(2, "Error\n", 6);
	exit(err_number);
}

// Creating a stack if it does not exist.
// Appending a new node to the end of the existing node.
void	list_birth(t_id_list **lst, t_id_list *node)
{
	if (!*lst)
		*lst = node;
	else
		(ft_lstlast(*lst))->next = node;
}

t_id_list	*node_birth(pid_t pid)
{
	t_id_list	*node;

	node = ft_calloc(1, sizeof(t_id_list));
	if (!node)
		error_mall_exit(5);
	node->id = pid;
	node->next = NULL;
	return (node);
}