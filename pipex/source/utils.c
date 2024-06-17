/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:54:53 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/09 16:00:26 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

// Displays an error message using perror(), closes the pipe (if provided),
// and exits with failure status.
void	perror_and_exit(char *msg, int *pipe_ends)
{
	perror(msg);
	if (pipe_ends)
	{
		if (close(pipe_ends[0]) == -1)
			perror("Error closing pipe end [0]");
		if (close(pipe_ends[1]) == -1)
			perror("Error closing pipe end [1]");
	}
	exit (EXIT_FAILURE);
}
