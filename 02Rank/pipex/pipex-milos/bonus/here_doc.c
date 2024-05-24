/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:36:08 by mitadic           #+#    #+#             */
/*   Updated: 2024/03/04 12:47:37 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	prompt_and_pass(int *fds, char *limiter)
{
	char	*input;
	char	*limitn;
	int		retval;

	input = NULL;
	limitn = ft_strjoin(limiter, "\n");
	retval = 1;
	while (1)
	{
		write(0, "> ", 2);
		input = get_next_line(0);
		if (!input)
			retval = -1;
		else if (ft_strcmp(input, limitn) == 0)
			retval = 0;
		if (retval == -1 || retval == 0)
			break ;
		ft_putstr_fd(input, fds[1]);
		free (input);
		input = NULL;
	}
	free (input);
	free (limitn);
	close(STDIN_FILENO);
	return (retval);
}

// has a special waitpid inside ch1_here that waits for gnl input to complete.
// this is the reason why go_wait gets called with such adjusted arguments.
void	go_piping_here(int prcs_count, char **argv, char **my_paths)
{
	int		fds[2][2];
	int		i;
	pid_t	*child;

	prep(fds, prcs_count, &child, my_paths);
	ch1_here(fds, argv, child, my_paths);
	i = 0;
	while (++i < (prcs_count - 1))
	{
		if (reuse_pipe(i, prcs_count, fds) < 0)
			free4exefail(my_paths, child, "reuse pipe");
		fork_one(i, child, my_paths, "ch_mid fork");
		if (!child[i])
		{
			ch_mid_prc(fds[1 - (i % 2)], fds[i % 2], \
					argv[i + 2], my_paths);
			free4exefail_noerr(my_paths, child);
		}
	}
	fork_one(i, child, my_paths, "ch_last fork");
	if (!child[i])
		ch_last_here(fds[1 - (i % 2)], &argv[i + 2], child, my_paths);
	pipe_closer(i, fds);
	go_wait(prcs_count - 1, &child[1], my_paths);
	free(child);
}
