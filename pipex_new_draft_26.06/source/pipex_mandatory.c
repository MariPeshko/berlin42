/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mandatory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:12:50 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/25 19:12:50 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"
#include <stdio.h>

static int	open_outfile(char *name_file, int open_fd)
{
	int	file_out;

	file_out = open(name_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (file_out == -1)
	{
		error_file(name_file);
		if (close(open_fd) == -1)
			print_stderr("close");
		exit(EXIT_FAILURE);
	}
	else
		return (file_out);
}

void	second_child(int *fd, char **argv, char *env[], int fd_f)
{
	int	file_out;

	file_out = open_outfile(argv[4], fd_f);
	dup2(fd[0], fd_f);
	close(fd[0]);
	close(fd[1]);
	dup2(file_out, STDOUT_FILENO);
	close(file_out);
	call_cmd(argv[3], env);
}

static void	second_command(char **argv, char *env[], int fd_f)
{
	int		fd[2];
	pid_t	p;
	int		pp_ret;

	pp_ret = pipe(fd);
	if (pp_ret == -1)
		perror_and_exit("pipe", NULL);
	p = fork();
	if (p < 0)
		perror_and_exit("fork fail", fd);
	else if (p == 0)
		second_child(fd, argv, env, fd_f);
	else if (p > 0)
	{
		close(fd[0]);
		close(fd[1]);
		waitpid(p, NULL, 0);
	}
}

static void	first_command(char **argv, char *env[])
{
	int		fd[2];
	pid_t	p;
	int		pp_ret;

	pp_ret = pipe(fd);
	if (pp_ret == -1)
		perror_and_exit("pipe", NULL);
	p = fork();
	if (p < 0)
		perror_and_exit("fork fail", fd);
	else if (p == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		call_cmd(argv[2], env);
	}
	else if (p > 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(p, NULL, 0);
		second_command(argv, env, fd[0]);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	int	file;

	check_args(argc, argv, env);
	file = open(argv[1], O_RDONLY);
	if (file == -1)
		perror("error infile");
	dup2(file, STDIN_FILENO);
	close(file);
	first_command(argv, env);
	return (0);
}
