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

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h> // waitpid, pid_t, WIFEXITED(status)

#include "../incl/pipex.h"
#include "libft/libft.h"
#include <stdio.h>

// This function checks for the number of arguments. If there are less than
// two arguments, then a message is output to the standard error and the
// program exit. Next, in function call 'check_cmd' each argument is checked
// in order (except the last one, the last argument can be an output file.)
// It checks if the arguments are existing commands. Next, in function call
// 'check_run_or_not', the function is checking if the program contimues or
// not. If any of command-argument is not vald, the program exit.
void check_args(int argc, char **argv, char *env[])
{
	int i;

	i = 1;
	if (argc < 5)
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

static void second_child(char **argv, char *env[], int fd_f)
{
	fprintf(stderr, "2nd\n");
	int fd[2];
	pid_t p;
	int pp_ret;

	int file_out = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	pp_ret = pipe(fd);
	if (pp_ret == -1)
		perror_and_exit("pipe", NULL);
	p = fork();
	if (p < 0)
		perror_and_exit("fork fail", fd);
	else if (p == 0)
	{
		dup2(fd[0], fd_f);
		close(fd[0]);

		close(fd[1]);

		dup2(file_out, STDOUT_FILENO);
		close(file_out);
		call_cmd(argv[3], env);
	}
	else if (p > 0)
	{
		close(fd[0]);
		close(fd[1]);
		waitpid(p, NULL, 0);
	}
}

static void first_child(char **argv, char *env[])
{
	int fd[2];
	pid_t p;
	int pp_ret;

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
		second_child(argv, env, fd[0]);
	}
}

int main(int argc, char *argv[], char *env[])
{
	int file;

	check_args(argc, argv, env);
	file = open(argv[1], O_RDONLY);
	if (file == -1)
		perror("error infile");
	dup2(file, STDIN_FILENO);
	close(file);
	first_child(argv, env);
	return (0);
}
