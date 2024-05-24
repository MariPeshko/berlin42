/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:11:49 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/19 15:38:11 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perr_n_exit_errno(char *str)
{
	perror(str);
	exit(errno);
}

void	perr_n_exit_num(char *str, int num)
{
	perror(str);
	exit(num);
}

int	go_wait(pid_t child1, pid_t child2)
{
	int		status1;
	int		status2;
	pid_t	wpid1;
	pid_t	wpid2;

	wpid1 = waitpid(child1, &status1, 0);
	if (wpid1 < 0)
		return (0);
	wpid2 = waitpid(child2, &status2, 0);
	if (wpid2 < 0)
		return (0);
	return (1);
}

int	closer_of_closes(int *fds)
{
	if (close(fds[0]) < 0)
		return (0);
	if (close(fds[1]) < 0)
		return (0);
	return (1);
}

char	**get_cmdstrarr(char *cmdandopts)
{
	char	**strarr;

	strarr = (char **)malloc(4 * sizeof(char *));
	if (!strarr)
		return (NULL);
	strarr[0] = NULL;
	strarr[1] = NULL;
	strarr[2] = NULL;
	strarr[0] = ft_strdup("sh");
	strarr[1] = ft_strdup("-c");
	strarr[2] = ft_strdup(cmdandopts);
	if (!strarr[0] || !strarr[1] || !strarr[2])
	{
		free (strarr[0]);
		free (strarr[1]);
		free (strarr[2]);
		free (strarr);
		return (NULL);
	}
	strarr[3] = NULL;
	return (strarr);
}
