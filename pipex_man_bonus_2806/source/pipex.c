/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:12:50 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/28 20:18:20 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

// Parameter 'p' - to open a file in TRUNK mode (not APPEND mode).
void	second_child(int *fd, char **argv, char *env[], int read_first_cmd)
{
	int	file_out;

	w_dup2(fd[0], read_first_cmd, fd[1]);
	file_out = open_outfile(argv[4], 'p');
	if (file_out == -2)
	{
		close(read_first_cmd);
		close(fd[0]);
		close(fd[1]);
	}
	w_dup2(file_out, STDOUT_FILENO, read_first_cmd);
	call_cmd(argv[3], env);
}

static void	second_command(char **argv, char *env[], int read_first_cmd)
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
		second_child(fd, argv, env, read_first_cmd);
	else if (p > 0)
	{
		close(fd[0]);
		close(fd[1]);
		waitpid(p, NULL, 0);
	}
}

void	first_child(int *fd, char **argv, char *env[])
{
	close(fd[0]);
	w_dup2(fd[1], STDOUT_FILENO, -2);
	call_cmd(argv[2], env);
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
		first_child(fd, argv, env);
	else if (p > 0)
	{
		close(fd[1]);
		w_dup2(fd[0], STDIN_FILENO, -2);
		waitpid(p, NULL, 0);
		second_command(argv, env, fd[0]);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	int	file;

	check_args(argc, argv, env);
	file = open_infile(argv[1]);
	w_dup2(file, STDIN_FILENO, -2);
	first_command(argv, env);
	return (0);
}
