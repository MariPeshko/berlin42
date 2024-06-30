/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:11:17 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/30 17:49:53 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

void	last_child(char *argv, char **env, int read_from, int write_to)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		w_errpipe_close(read_from);
	pid = fork();
	if (pid == -1)
		w_errfork_close(read_from, fd);
	if (pid == 0)
	{
		close(fd[0]);
		w_dup2(write_to, STDOUT_FILENO, -2);
		close(write_to);
		if (!*argv)
			exit(EXIT_FAILURE);
		call_cmd(argv, env);
	}
	else
	{
		close(fd[1]);
		dup2(read_from, STDIN_FILENO);
		close(read_from);
	}
}

int	child_process(char *argv, char **env, int read_from)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		w_errpipe_close(read_from);
	pid = fork();
	if (pid == -1)
		w_errfork_close(read_from, fd);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		if (!*argv)
			exit(EXIT_FAILURE);
		call_cmd(argv, env);
	}
	else
	{
		close(fd[1]);
		dup2(read_from, STDIN_FILENO);
		close(read_from);
	}
	return (fd[0]);
}

// If no access to infile, then we start execution not from the 1st
// command, but from the 2nd command. This is a behaviour of bash.
static int	cmd_to_start(char *name_file)
{
	int	file_in;

	file_in = open(name_file, O_RDONLY);
	if (access(name_file, R_OK) != 0)
		return (3);
	else
	{
		close(file_in);
		return (2);
	}
}

void	multi_pipe(int argc, char **argv, char **env)
{
	int	cmd;
	int	read_from;
	int	write_to;

	check_args_multi(argc, argv, env);
	read_from = open_infile(argv[1]);
	w_dup2(read_from, STDIN_FILENO, -2);
	cmd = cmd_to_start(argv[1]);
	while (cmd < argc - 2)
	{
		if (acces_cmd(argv[cmd], env) == -6)
		{
			read_from = open("/dev/null", O_RDONLY);
			w_dup2(read_from, STDIN_FILENO, -2);
		}
		else
			read_from = child_process(argv[cmd], env, read_from);
		cmd++;
	}
	write_to = open_outfile(argv[argc - 1], 'p');
	last_child(argv[cmd], env, read_from, write_to);
}

int	main(int argc, char **argv, char **env)
{
	if (argv[1] == NULL)
		how_execute_pipex();
	else if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
		here_doc(argc, argv, env);
	else
		multi_pipe(argc, argv, env);
}
