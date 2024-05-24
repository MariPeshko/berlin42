/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:11:49 by mitadic           #+#    #+#             */
/*   Updated: 2024/03/01 16:41:55 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*crt_cmdpath(char *path, char *cmd)
{
	char	*concat_step1;
	char	*concat_step2;

	concat_step1 = ft_strjoin(path, "/");
	if (!concat_step1)
		return (NULL);
	concat_step2 = ft_strjoin(concat_step1, cmd);
	free(concat_step1);
	if (!concat_step2)
		return (NULL);
	return (concat_step2);
}

int	go_malloc_int(int count, int **arr)
{
	*arr = (int *)malloc(count * sizeof(int));
	if (!(*arr))
		return (-1);
	return (1);
}

// Would real shell abort if (wpid[i] < 0) ?
void	go_wait(int prcs_count, pid_t *child, char **my_paths)
{
	int		i;
	pid_t	*wpid;
	int		*status;

	i = -1;
	wpid = (pid_t *)malloc(sizeof(pid_t) * prcs_count);
	status = (int *)malloc(sizeof(int) * prcs_count);
	if (!wpid || !status)
		purge_waiter(wpid, status, my_paths, child);
	while (++i < prcs_count)
	{
		wpid[i] = waitpid(child[i], &status[i], 0);
		if (wpid[i] < 0)
			purge_waiter(wpid, status, my_paths, child);
	}
	free(wpid);
	free(status);
}

void	close_all_pipeends(int (*fds)[2])
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		if (close(fds[i][0]) < 0)
			perror("close");
		fds[i][0] = -1;
		if (close(fds[i][1]) < 0)
			perror("close");
		fds[i][1] = -1;
	}
}

// 'else' == the read end of the pipe leading into 'last' is already closed
void	pipe_closer(int count, int (*fds)[2])
{
	if (count < 2)
		close_all_pipeends(fds);
	else
	{
		if (close(fds[count % 2][0]) < 0)
			perror("close");
		if (close(fds[1 - (count % 2)][0]) < 0)
			perror("close");
		if (close(fds[1 - (count % 2)][1]) < 0)
			perror("close");
	}
	if (close(STDIN_FILENO) < 0)
		perror("close");
	if (close(STDOUT_FILENO) < 0)
		perror("close");
}
