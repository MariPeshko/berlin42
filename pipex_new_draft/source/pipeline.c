/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:16:10 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/18 20:19:22 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

// Prints an error message related to file operations, e.g. open().
static void	file_err_msg(char *pre, char *file)
{
	ft_putstr_fd(pre, STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

// Executes the left side of the process (in a child process).
// - Opens the input file ('infile') specified by the first CL argument.
// - Closes the unused read end of the pipe.
// - (to connect the write end [1] to the standard output)
// - Redirects standard output to write to the write end of the pipe,
//   which will serve as the input for the right side of the pipeline.
// - Closes the write end [1]
// - Redirects standard input to read from the input
//   file ('< infile' in CL).
// - Executes the command (second CL argument) using 'call_cmd'/'execve'.
void	pipeline_left(char **argv, char **env, int *pipe_ends)
{
	int	infile_fd;

	if (!*argv[2])
		perror_and_exit("No first command", pipe_ends);
	infile_fd = open(argv[1], O_RDONLY);
	if (close(pipe_ends[0]) == -1)
		perror_and_exit("close", pipe_ends);
	if (infile_fd == -1)
	{
		file_err_msg("pipex: ", argv[1]);
		if (close(pipe_ends[1]) == -1)
			perror_and_exit("close", pipe_ends);
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_ends[1], STDOUT_FILENO) == -1)
	 	perror_and_exit("dup2", pipe_ends);
	if (close(pipe_ends[1]) == -1)
		perror_and_exit("close", pipe_ends);
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		perror_and_exit("dup2", pipe_ends);
	if (close(infile_fd) == -1)
		perror_and_exit("close", pipe_ends);
	call_cmd(argv[2], env);
}

// Executes the right side of the process (in a second child process).
// - Opens the output file ('outfile') specified by the fourth CL argument.
// 	 If the outfile does not exist, it creates it with 'rw-r--r--' permissions.
// - Closes the unused write end of the pipe.
// - Redirects standard input to read from the read end of the pipe,
//   which receives input from the previous process in the pipeline.
//   (to connect the write end of the pipe fd[0] to the standard input)
// - Closes the read end (fd[0]). 
// - Redirects standard output to write to the output file ('> outfile' in CL).
// - Executes the command (third CL argument) using 'call_cmd'/'execve'.
void	pipeline_right(char **argv, char **env, int *pipe_ends)
{
	int	outfile_fd;
	
	outfile_fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (!*argv)
		perror_and_exit("No last command", pipe_ends);
	if (close(pipe_ends[1]) == -1)
		perror_and_exit("close", pipe_ends);
	if (outfile_fd == -1)
	{
		file_err_msg("pipex: ", argv[4]);
		if (close(pipe_ends[0]) == -1)
			perror_and_exit("close", pipe_ends);
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_ends[0], STDIN_FILENO) == -1)
	 	perror_and_exit("dup2", pipe_ends);
	if (close(pipe_ends[0]) == -1)
		perror_and_exit("close", pipe_ends);
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		perror_and_exit("dup2", pipe_ends);
	if (close(outfile_fd) == -1)
		perror_and_exit("close", pipe_ends);
	call_cmd(argv[3], env);
}

// Closes the pipe and waits for child processes to finish.
// Forwards the last child process' exit status to the parent.
void	parent_process(int child_id_1, int child_id_2, int *pipe_ends)
{
	int	child_status;

	if (close(pipe_ends[0]) == -1)
		perror_and_exit("close", pipe_ends);
	if (close(pipe_ends[1]) == -1)
		perror_and_exit("close", pipe_ends);

	waitpid(child_id_1, NULL, 0);
	waitpid(child_id_2, &child_status, 0);
	if (WIFEXITED(child_status) && WEXITSTATUS(child_status) != EXIT_SUCCESS)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
