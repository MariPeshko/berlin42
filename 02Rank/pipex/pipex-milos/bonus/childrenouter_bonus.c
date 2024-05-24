/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childrenouter_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 23:40:08 by mitadic           #+#    #+#             */
/*   Updated: 2024/03/04 12:45:26 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ch_last_exe(char *argv, char **my_paths)
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

void	ch_last_prc(int *fds, char **argv, pid_t *child, char **my_paths)
{
	int	outfile_fd;

	outfile_fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
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

void	ch1_exe(char **argv, char **my_paths)
{
	int		i;
	char	*cmdpath;
	char	**cmdandopts;

	i = -1;
	cmdandopts = ft_split(argv[2], ' ');
	if (!cmdandopts)
		fr1_perr_n_exit_errno(my_paths, "malloc fail @ Child1");
	while (my_paths[++i])
	{
		cmdpath = crt_cmdpath(my_paths[i], cmdandopts[0]);
		if (!cmdpath)
			fr2_perr_n_exit_errno(my_paths, cmdandopts, "malloc \
					fail @ Child1");
		if (access(cmdpath, X_OK) == 0)
			execve(cmdpath, cmdandopts, NULL);
		free(cmdpath);
	}
	perror(cmdandopts[0]);
	free_strarr(cmdandopts);
}

void	ch1_prc(int *fds, char **argv, pid_t *child, char **my_paths)
{
	int	infile_fd;

	if (access(argv[1], R_OK) != 0)
		free4exefail(my_paths, child, "access to infile");
	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd < 0)
		free4exefail(my_paths, child, "open in Child1");
	if (close(fds[0]) < 0)
		free4exefail(my_paths, child, "close(fds[0]) in Child1");
	if (dup2(infile_fd, STDIN_FILENO) < 0)
		free4exefail(my_paths, child, "dup2 in Child1");
	if (close(infile_fd) < 0)
		free4exefail(my_paths, child, "close(infile_fd) in Child1");
	if (dup2(fds[1], STDOUT_FILENO) < 0)
		free4exefail(my_paths, child, "dup2 in Child1");
	if (close(fds[1]) < 0)
		free4exefail(my_paths, child, "close(fds[1]) in Child1");
	ch1_exe(argv, my_paths);
	free4exefail_noerr(my_paths, child);
}

void	ch1_ctrl(int (*fds)[2], char **argv, pid_t *child, char **my_paths)
{
	child[0] = fork();
	if (child[0] < 0)
		free4exefail(my_paths, child, "fork");
	if (!child[0])
		ch1_prc(fds[0], argv, child, my_paths);
}
