/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childrenmid_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 00:19:08 by mitadic           #+#    #+#             */
/*   Updated: 2024/03/04 12:54:02 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ch_mid_exe(char *cmd, char **my_paths)
{
	int		i;
	char	*cmdpath;
	char	**cmdandopts;

	i = -1;
	cmdandopts = ft_split(cmd, ' ');
	if (!cmdandopts)
		fr1_perr_n_exit_errno(my_paths, "Malloc fail @ Ch_mid");
	while (my_paths[++i])
	{
		cmdpath = crt_cmdpath(my_paths[i], cmdandopts[0]);
		if (!cmdpath)
			fr2_perr_n_exit_errno(my_paths, cmdandopts, "Malloc \
					fail @ Ch_mid");
		if (access(cmdpath, X_OK) == 0)
			execve(cmdpath, cmdandopts, NULL);
		free(cmdpath);
	}
	perror(cmdandopts[0]);
	free_strarr(cmdandopts);
}

// pipein == fds[0] when this is called for the 1st time
void	ch_mid_prc(int *pipein, int *pipeout, char *cmd, char **my_paths)
{
	if (close(pipeout[0]) < 0)
		return ;
	if (dup2(pipein[0], STDIN_FILENO) < 0)
		return ;
	if (close(pipein[0]) < 0)
		return ;
	if (dup2(pipeout[1], STDOUT_FILENO) < 0)
		return ;
	if (close(pipeout[1]) < 0)
		return ;
	ch_mid_exe(cmd, my_paths);
	return ;
}

// The 'if' checks whether we even need any reopening, i.e. more pipes
// Then the pipe which is not leading into child is reopened and points OUT.
int	reuse_pipe(int i, int prcs_count, int (*fds)[2])
{
	if (i > 1 && i != (prcs_count -1))
	{
		if (close(fds[i % 2][0]) < 0 || close(fds[1 - (i % 2)][1]) < 0)
			return (-1);
		if (pipe(fds[i % 2]) < 0)
			return (-1);
	}
	else
	{
		if (close(fds[1 - (i % 2)][1]) < 0)
			return (-1);
	}
	return (0);
}
