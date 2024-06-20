/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:20:40 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/18 18:41:31 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"
#include <stdio.h>

// The child process reads the input and execute a command.
// The parent process writes and redirect data to the output.
static void mid_processes(char *argv, char **env, int *fd)  
{
	int mid_id;

	mid_id = fork();
	if (mid_id == 0)
	{
		if (close(fd[0]) == -1) // Close the write end of the pipe
			perror_and_exit("close", fd);
		if (dup2(fd[1], STDOUT_FILENO) == -1) // Data is being written out to stdout
			perror_and_exit("dup2", fd);
		fprintf(stderr, "in mid_processes child\n");
		call_cmd(argv, env);
	}
	else if (mid_id > 0)
	{
		if (close(fd[1]) == -1) // Close the write end of the pipe
			perror_and_exit("close", fd);
		if (dup2(fd[0], STDIN_FILENO) == -1) // Data is being read in from stdin
			perror_and_exit("dup2", fd);
		waitpid(mid_id, NULL, 0);
		fprintf(stderr, "in mid_processes parent\n");
	}
}

static void check_args(int argc, char **argv, char **env)
{
	int i;

	i = 1;
	if (argc < 2)
	{
		write(STDERR_FILENO, "Your program will be executed like this\n", 41);
		ft_putstr_fd("> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file\n",
					 STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	while (argv[++i + 1] != NULL)
		check_cmd(argv[i], env);
	i = 1;
	while (argv[++i + 1] != NULL)
		check_run_or_not(argv[i], env);
}

// static int count_cmds(int argc)
// {
// 	int n;
// 	n = argc - 3;
// 	return (n);
// }

// Manages the creation of a pipeline, forking processes, and executing
// commands within the pipeline. Each half of the pipeline (left + right)
// is handled by a child process, while the parent process ensures to close
// the pipe and propagate the exit status of the last child process.
int main(int argc, char **argv, char **env)
{
	int pipe_ends[2];
	pid_t p_left_id;
	pid_t p_right_id;
	int pipe_return;

	check_args(argc, argv, env);
	int n = 3; // ./pipex 333.txt cat cat cat cat cat 333out.txt
	int c = 3;

	pipe_return = pipe(pipe_ends);
	if (pipe_return == -1)
		perror_and_exit("pipe", NULL);
	p_left_id = fork();
	printf("p_left_id: %d\n", p_left_id);
	if (p_left_id == -1)
		perror_and_exit("fork", pipe_ends);
	else if (p_left_id == 0)
		pipeline_left(argv, env, pipe_ends);

	if (p_left_id > 0) /// p_left_id - if of 1st child process
	{
		waitpid(p_left_id, NULL, 0);
		while (n >= 1)
		{
			fprintf(stderr, "in while\n");
			mid_processes(argv[c++], env, pipe_ends);
			n--;
		}
		p_right_id = fork();
		if (p_right_id == -1)
			perror_and_exit("fork", pipe_ends);
		else if (p_right_id == 0)
			pipeline_right(argv, env, pipe_ends);
		else
			parent_process(p_left_id, p_right_id, pipe_ends, n);
	}
}
