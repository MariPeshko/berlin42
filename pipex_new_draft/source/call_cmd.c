/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:55:30 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/26 15:55:30 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"
#include <stdio.h>

void	call_cmd(char *argument, char *env[])
{
	char	**cmd_plus_args;
	char	*cmd_path;

	cmd_plus_args = ft_split(argument, ' ');
	if (!cmd_plus_args)
		perror_and_exit("malloc", NULL);
	if (access(cmd_plus_args[0], F_OK | X_OK) == 0)
	{
		if (execve(cmd_plus_args[0], cmd_plus_args, env) == -1)
		{
			ft_freestr(cmd_plus_args);
			perror_and_exit("execve", NULL);
		}
	}
	cmd_path = get_path(cmd_plus_args[0], env);
	if (execve(cmd_path, cmd_plus_args, env) == -1)
	{
		free(cmd_path);
		ft_freestr(cmd_plus_args);
		perror_and_exit("execve", NULL);
	}
}
