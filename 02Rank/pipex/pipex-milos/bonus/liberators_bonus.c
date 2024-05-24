/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberators_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:11:45 by mitadic           #+#    #+#             */
/*   Updated: 2024/03/25 12:29:06 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	purge_waiter(pid_t *wpid, int *status, char **my_paths, pid_t *child)
{
	free(wpid);
	free(status);
	free_strarr(my_paths);
	free(child);
	strerror(errno);
	exit(errno);
}

void	free_strarr(char **strarr)
{
	int	i;

	if (!strarr)
		return ;
	i = -1;
	while (strarr[++i])
		free (strarr[i]);
	free (strarr);
}

void	fr1_perr_n_exit_errno(char **strarr, char *str)
{
	perror(str);
	free_strarr(strarr);
	exit(errno);
}

void	fr2_perr_n_exit_errno(char **strarr1, char **strarr2, char *str)
{
	free_strarr(strarr1);
	free_strarr(strarr2);
	perror(str);
	exit(errno);
}

void	fr1_put_str_exit_num(char **strarr, char *str, int num)
{
	if (!str)
		return ;
	ft_putstr_fd(str, 2);
	free_strarr(strarr);
	exit(num);
}
