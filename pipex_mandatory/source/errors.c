/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:46:05 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/27 16:20:32 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

void	error_file(char *outfile)
{
	ft_putstr_fd("no such file or directory: ", STDERR_FILENO);
	ft_putstr_fd(outfile, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	no_cmd_path(char **cmd_plus_args)
{
	ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
	ft_putstr_fd(cmd_plus_args[0], STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_freestr(cmd_plus_args);
}

// Printing a message on standart error describing the meaning of
// the value of given argument.
void	print_stderr(char *what_error)
{
	perror(what_error);
}

void	perror_and_exit(char *what_error, int *pipe_fd)
{
	perror(what_error);
	if (pipe_fd)
	{
		if (close(pipe_fd[0]) == -1)
			perror("Error closing pipe [0]");
		if (close(pipe_fd[1]) == -1)
			perror("Error closing pipe [1]");
	}
	exit (EXIT_FAILURE);
}
