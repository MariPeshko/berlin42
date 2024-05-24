/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:11:45 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/19 13:11:46 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	free_strarr(strarr);
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
