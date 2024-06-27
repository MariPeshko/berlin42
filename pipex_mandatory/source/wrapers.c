/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:30:17 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/27 16:23:23 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

void	w_dup2(int dupfd, int newfd, int fd_open)
{
	if (dup2(dupfd, newfd) == -1)
	{
		if (fd_open != -2)
			close(fd_open);
		print_stderr("dup2");
		close(dupfd);
		exit(EXIT_FAILURE);
	}
	else
		close(dupfd);
}
