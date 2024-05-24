/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:36:08 by mitadic           #+#    #+#             */
/*   Updated: 2024/03/04 12:47:17 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	prep(int (*fds)[2], int prcs_count, pid_t **child, char **my_paths)
{
	*child = NULL;
	*child = (pid_t *)malloc(prcs_count * sizeof(pid_t));
	if (!(*child))
		fr1_perr_n_exit_errno(my_paths, "malloc fail @ Child1");
	if (pipe(fds[0]) < 0 || pipe(fds[1]) < 0)
		free4exefail(my_paths, *child, "open pipes");
}

void	fork_one(int i, pid_t *child, char **my_paths, char *errmsg)
{
	child[i] = fork();
	if (child[i] < 0)
		free4exefail(my_paths, child, errmsg);
}

// mid-children: while (i (which starts at 1) < (prcs_count - last child))
void	go_piping(int prcs_count, char **argv, char **my_paths)
{
	int		fds[2][2];
	int		i;
	pid_t	*child;

	prep(fds, prcs_count, &child, my_paths);
	ch1_ctrl(fds, argv, child, my_paths);
	i = 0;
	while (++i < (prcs_count - 1))
	{
		if (reuse_pipe(i, prcs_count, fds) < 0)
			free4exefail(my_paths, child, "reuse pipe");
		fork_one(i, child, my_paths, "ch_mid fork");
		if (!child[i])
		{
			ch_mid_prc(fds[1 - (i % 2)], fds[i % 2], argv[i + 2], my_paths);
			free4exefail_noerr(my_paths, child);
		}
	}
	fork_one(i, child, my_paths, "ch_last fork");
	if (!child[i])
		ch_last_prc(fds[1 - (i % 2)], &argv[i + 2], child, my_paths);
	pipe_closer(i, fds);
	go_wait(prcs_count, child, my_paths);
	free(child);
}
