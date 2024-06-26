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

static void	check_args(int argc, char **argv, char **env)
{
	int i;

	i = 1;
	if (argc < 4)
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

int main(int argc, char **argv, char **env)
{
	int pipe_ends[2];
	pid_t p_left_id;
	pid_t p_right_id;
	int pipe_return;

	check_args(argc, argv, env);
	
	pipe_return = pipe(pipe_ends);
	if (pipe_return == -1)
		perror_and_exit("pipe", NULL);
	p_left_id = fork();
	if (p_left_id == -1)
		perror_and_exit("fork", pipe_ends);
	else if (p_left_id == 0)
		pipeline_left(argv, env, pipe_ends);
	if (p_left_id > 0) /// p_left_id - if of 1st child process
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
