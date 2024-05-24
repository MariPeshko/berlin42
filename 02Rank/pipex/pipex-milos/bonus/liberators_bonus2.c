/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberators_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:29:16 by mitadic           #+#    #+#             */
/*   Updated: 2024/03/25 12:37:24 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free4exefail_noerr(char **strarr, pid_t *child)
{
	free_strarr(strarr);
	free(child);
	exit(errno);
}

void	free4exefail(char **strarr, pid_t *child, char *str)
{
	free_strarr(strarr);
	free(child);
	perror(str);
	exit(errno);
}
