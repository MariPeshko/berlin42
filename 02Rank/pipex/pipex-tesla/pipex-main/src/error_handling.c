/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:20:00 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/08 14:22:01 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "./pipex.h"

int	print_error(char *msg, int code)
{
	perror(msg);
	return (code);
}

int	printf_error(char *msg, int code)
{
	ft_printf(2, msg);
	return (code);
}

void	close_fds(t_pipex **data)
{
	if ((*data)->in_fd > 0)
		close((*data)->in_fd);
	if ((*data)->out_fd > 0)
		close((*data)->out_fd);
}

void	destroy(t_pipex **data)
{
	int	i;

	i = 0;
	close_fds(data);
	if ((*data)->path)
		list_free((*data)->path);
	if ((*data)->cmds)
		list_free((*data)->cmds);
	if ((*data)->cmd_args)
	{
		while (i < (*data)->row_c)
		{
			list_free((*data)->cmd_args[i]);
			i++;
		}
		free((*data)->cmd_args);
	}
	free((*data));
}
