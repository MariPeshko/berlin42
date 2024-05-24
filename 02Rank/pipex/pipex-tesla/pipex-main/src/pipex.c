/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:16:36 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/11 20:01:54 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "./pipex.h"

int	pend(int pipe[2], t_pipex **data, int code)
{
	if (pipe[0] >= 0)
		close(pipe[0]);
	if (pipe[1] >= 0)
		close(pipe[1]);
	destroy(data);
	exit (code);
	return (code);
}

int	end(t_pipex **data, int code)
{
	destroy(data);
	exit (code);
	return (code);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex		*data;
	int			pipefd[2];

	data = init_pipex(env);
	if (check_input(argc, argv, &data) == 1)
		end(&data, 1);
	if (parse_fd(argc, argv, &data) == 1)
		end(&data, 1);
	if (parse_cmds(argc, argv, &data) == 1)
		end(&data, 1);
	if (parse_args(argv, &data) == 1)
		end(&data, 1);
	if (pipe(pipefd) == -1)
		return (printf_error("[main]: Pipe failure.", 1));
	exec_first(&data, env, pipefd);
	exec_last(&data, env, pipefd);
	end (&data, data->status);
	return (0);
}
