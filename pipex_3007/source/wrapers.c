/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:30:17 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/29 13:54:25 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

// argument 'fd_open' for an argument that is currently opened and in case of
// duplacating error need to beclosed before exit.
void	w_dup2(int dupfd, int newfd, int fd_open)
{
	if (dup2(dupfd, newfd) == -1)
	{
		if (fd_open != -2)
			close(fd_open);
		print_stderr("dup2");
		close(dupfd);
		exit(EXIT_FAILURE);
	}
	else
		close(dupfd);
}

void	w_errfork_close(int open_fd, int *pipe_fd)
{
	perror("Fork Error");
	close(open_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	exit(EXIT_FAILURE);
}

void	w_errpipe_close(int open_fd)
{
	close(open_fd);
	perror_and_exit("pipe", NULL);
}
