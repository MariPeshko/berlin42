/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_mid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:00:23 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/19 19:05:14 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"
#include <stdio.h>

void	pipeline_middle(char *argv, char **env, int *pipe_ends)
{

	//int	infile_fd;

	// if (!*argv)
	// 	perror_and_exit("No first command", pipe_ends);
	//infile_fd = open(argv[1], O_RDONLY);
	// if (close(pipe_ends[1]) == -1)
	// 	perror_and_exit("close", pipe_ends);
	// if (infile_fd == -1)
	// {
	// 	file_err_msg("pipex: ", argv[1]);
	// 	if (close(pipe_ends[1]) == -1)
	// 		perror_and_exit("close", pipe_ends);
	// 	exit(EXIT_FAILURE);
	// }
	if (dup2(pipe_ends[1], STDOUT_FILENO) == -1)
		perror_and_exit("dup2", pipe_ends);
	if (close(pipe_ends[1]) == -1)
		perror_and_exit("close", pipe_ends);
	if (dup2(pipe_ends[0], STDIN_FILENO) == -1)
		perror_and_exit("dup2", pipe_ends);
	if (close(pipe_ends[0]) == -1)
		perror_and_exit("close", pipe_ends);
	call_cmd(argv, env);
}