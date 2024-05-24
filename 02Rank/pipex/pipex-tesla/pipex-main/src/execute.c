/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:25:12 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/11 20:00:08 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "./pipex.h"

void	p_list(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		ft_printf(2, "%d: %s\n", i, lst[i]);
		i++;
	}
}

// Execute first command by inputting the contents of the 'infile' into it.
int	exec_first(t_pipex **data, char **env, int pipefd[2])
{
	pid_t	pid;
	char	*cmd;

	pid = fork();
	if (pid == -1)
		return (printf_error(RED"[exec_first]: Fork failure."R"\n", -1));
	if (!pid)
	{
		cmd = check_cmd((*data)->cmds[0], (*data)->path);
		if (!cmd)
			return (pend(pipefd, data, 127));
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		dup2((*data)->in_fd, STDIN_FILENO);
		if (execve(cmd, (*data)->cmd_args[0], env) == -1)
			exit(print_error(RED"Error (exec_first)"R, 1));
	}
	else
		close(pipefd[1]);
	return (0);
}

// Execute last command by outputting the result of the last command
// into 'outfile'.
int	exec_last(t_pipex **data, char **env, int pipefd[2])
{
	pid_t	pid;
	char	*cmd;

	pid = fork();
	if (pid == -1)
		return (print_error("(exec_last) Fork failure.", -1));
	if (!pid)
	{
		cmd = check_cmd((*data)->cmds[1], (*data)->path);
		if (!cmd)
			return (pend(pipefd, data, 127));
		dup2(pipefd[0], STDIN_FILENO);
		dup2((*data)->out_fd, STDOUT_FILENO);
		if (execve(cmd, (*data)->cmd_args[1], env) == -1)
			exit (print_error(RED"Error (exec_last)"R, 1));
	}
	else
		close(pipefd[0]);
	return (0);
}
