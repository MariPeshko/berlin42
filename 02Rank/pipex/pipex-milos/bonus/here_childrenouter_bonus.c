/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_childrenouter_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:40:08 by mitadic           #+#    #+#             */
/*   Updated: 2024/03/04 12:54:47 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ch_last_exe_here(char *argv, char **my_paths)
{
	int		i;
	char	*cmdpath;
	char	**cmdandopts;

	i = -1;
	cmdandopts = ft_split(argv, ' ');
	if (!cmdandopts)
		fr1_perr_n_exit_errno(my_paths, "malloc fail @ ch_last");
	while (my_paths[++i])
	{
		cmdpath = crt_cmdpath(my_paths[i], cmdandopts[0]);
		if (!cmdpath)
			fr2_perr_n_exit_errno(my_paths, cmdandopts, "malloc \
					fail @ ch_last");
		if (access(cmdpath, X_OK) == 0)
			execve(cmdpath, cmdandopts, NULL);
		free(cmdpath);
	}
	perror(cmdandopts[0]);
	free_strarr(cmdandopts);
}

void	ch_last_here(int *fds, char **argv, pid_t *child, char **my_paths)
{
	int	outfile_fd;

	outfile_fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (outfile_fd < 0)
		free4exefail(my_paths, child, "open in ch_last");
	if (close(fds[1]) < 0)
		free4exefail(my_paths, child, "close(fds[1]) in ch_last");
	if (dup2(fds[0], STDIN_FILENO) < 0)
		free4exefail(my_paths, child, "dup2 in ch_last");
	if (close(fds[0]) < 0)
		free4exefail(my_paths, child, "close(fds[0]) in ch_last");
	if (dup2(outfile_fd, STDOUT_FILENO) < 0)
		free4exefail(my_paths, child, "dup2 in ch_last");
	if (close(outfile_fd) < 0)
		free4exefail(my_paths, child, "close(outfile_fd) in ch_last");
	ch_last_exe(argv[0], my_paths);
	free4exefail_noerr(my_paths, child);
}

// since no execve, close fds[0][1] only after done getting input,
// else it won't get passed
void	ch1_prc_here(int *fds, char **argv, pid_t *child, char **my_paths)
{
	if (close(fds[0]) < 0)
		free4exefail(my_paths, child, "close(fds[0]) in Child1");
	if (dup2(fds[1], STDOUT_FILENO) < 0)
		free4exefail(my_paths, child, "dup2 in Child1");
	if (prompt_and_pass(fds, argv[2]) < 0)
		free4exefail(my_paths, child, "input error");
	if (close(fds[1]) < 0)
		free4exefail(my_paths, child, "close(fds[1]) in Child1");
	free_strarr(my_paths);
	free(child);
	exit(0);
}

void	ch1_here(int (*fds)[2], char **argv, pid_t *child, char **my_paths)
{
	child[0] = fork();
	if (child[0] < 0)
		free4exefail(my_paths, child, "fork");
	if (!child[0])
		ch1_prc_here(fds[0], argv, child, my_paths);
	go_wait(1, child, my_paths);
}
