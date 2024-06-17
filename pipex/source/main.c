/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:20:40 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/09 18:01:20 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

// Verifies the correct number of CL arguments provided to the program.
static void	check_args(int argc)
{
	if (argc != 5)
	{
		write(STDERR_FILENO, "Your program will be executed like this\n", 41);
		write(STDERR_FILENO, "./pipex file1 cmd1 cmd2 file2\n", 31);
		exit(EXIT_FAILURE);
	}
}

// Manages the creation of a pipeline, forking processes, and executing
// commands within the pipeline. Each half of the pipeline (left + right)
// is handled by a child process, while the parent process ensures to close
// the pipe and propagate the exit status of the last child process.
int	main(int argc, char **argv, char **env)
{
	int		pipe_ends[2];
	pid_t	p_left_id;
	pid_t	p_right_id;
	int		pipe_return;

	check_args(argc);
	pipe_return = pipe(pipe_ends);
	if (pipe_return == -1)
		perror_and_exit("pipe", NULL);
	p_left_id = fork();
	if (p_left_id == -1)
		perror_and_exit("fork", pipe_ends);
	else if (p_left_id == 0)
		pipeline_left(argv, env, pipe_ends);
	else
	{
		p_right_id = fork();
		if (p_right_id == -1)
			perror_and_exit("fork", pipe_ends);
		else if (p_right_id == 0)
			pipeline_right(argv, env, pipe_ends);
		else
			parent_process(p_left_id, p_right_id, pipe_ends);
	}
}
