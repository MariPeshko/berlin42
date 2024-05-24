/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:14:14 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/08 12:19:25 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./pipex.h"

// Append to string array
int	append_tsa(char ****array2D, char ***newRow, int *rowCount)
{
	char	***temp;
	int		i;

	(*rowCount)++;
	temp = (char ***)malloc((*rowCount) * sizeof(char **));
	if (temp == NULL)
	{
		return (printf_error(RED"[append_tsa]: Memory allocation failed."R
				"\n", 1));
	}
	i = 0;
	ft_memcpy(temp, *array2D, (*rowCount - 1) * sizeof(char **));
	temp[*rowCount - 1] = *newRow;
	free(*array2D);
	*array2D = temp;
	return (0);
}

int	parse_args(char **argv, t_pipex **data)
{
	int		i;
	char	**entryv;

	i = 2;
	while (argv[i + 1])
	{
		entryv = ft_split(argv[i], ' ');
		if (!entryv)
			return (1);
		if (append_tsa(&((*data)->cmd_args), &entryv, &((*data)->row_c)) == 1)
			return (1);
		i++;
	}
	return (0);
}
