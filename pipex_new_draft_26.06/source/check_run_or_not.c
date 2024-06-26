/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_run_or_not.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:23:03 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/26 15:52:35 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"
#include <stdio.h>

// Displays an error message using perror(), closes the pipe (if provided),
// and exits with failure status.
static void	perror_cmd(char *msg)
{
	perror(msg);
}

int	check_run_or_not(char *argument, char *env[])
{
	char	**cmd_plus_args;
	char	*cmd_path;

	cmd_plus_args = ft_split(argument, ' ');
	if (!cmd_plus_args)
		perror_cmd("malloc");
	if (access(cmd_plus_args[0], F_OK | X_OK) == 0)
	{
		ft_freestr(cmd_plus_args);
		return (5);
	}
	cmd_path = get_path(cmd_plus_args[0], env);
	ft_freestr(cmd_plus_args);
	if (!cmd_path)
		exit (EXIT_FAILURE);
	else
	{
		free(cmd_path);
		return (5);
	}
}
