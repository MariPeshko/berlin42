/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:33:51 by gcollet           #+#    #+#             */
/*   Updated: 2024/06/22 17:58:20 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_fork(void)
{
	perror("Fork Error");
	exit(EXIT_FAILURE);
}

int	child_process(char *argv, char **envp, int read_from)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	fprintf(stderr, "child_process. new pipe\nfd[0]: %i, fd[1]: %i\n", fd[0], fd[1]);
	pid = fork();
	if (pid == -1)
		error_fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		fprintf(stderr, "close (fd[1]: %i)\n", fd[1]);
		close(fd[1]);
		fprintf(stderr, "I am reading data from %i\n", read_from);
		dup2(read_from, STDIN_FILENO);
		close(read_from);
		waitpid(pid, NULL, 0);
	}
	return(fd[0]);
}

/* Function who make a child process that will read from the stdin with
 get_next_line until it find the limiter word and then put the output inside a
 pipe. The main process will change his stdin for the pipe file descriptor. */
void	here_doc(char *limiter, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (argc < 6)
		usage();
	if (pipe(fd) == -1)
		error();
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	cmd;
	//int	input_file;
	int	write_to;
	int	read_from;

	if (argc >= 5)
	{
		cmd = 2;
		write_to = open_file(argv[argc - 1], 1);
		fprintf(stderr, "write_to: %i\n", write_to);
		read_from = open_file(argv[1], 2);
		fprintf(stderr, "write_to: %i\n", read_from);
		dup2(read_from, STDIN_FILENO);
		//fprintf(stderr, "input_file: %i\n", input_file);
		close(read_from);
		fprintf(stderr, "close read_from(%i)\n\n", read_from);
	}
	//read_from = input_file;
	while (cmd < argc - 2)
	{
		fprintf(stderr, "read_from: %i\n", read_from);
		read_from = child_process(argv[cmd++], envp, read_from);
		fprintf(stderr, "child_process returns read_from: %i\n\n", read_from);
	}
	close(read_from);
	fprintf(stderr, "close(%i)\n", read_from);
	dup2(write_to, STDOUT_FILENO);
	
	close(write_to);
	fprintf(stderr, "close(%i)\n", write_to);
	execute(argv[argc - 2], envp);
	usage();
}
