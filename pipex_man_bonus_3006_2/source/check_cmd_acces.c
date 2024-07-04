/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_acces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:23:03 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/30 17:47:30 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

void	free_cmd_and_path(char **cmd_plus_args, char *cmd_path)
{
	ft_freestr(cmd_plus_args);
	free(cmd_path);
}

int	acces_cmd(char *argument, char *env[])
{
	char	**cmd_plus_args;
	char	*cmd_path;

	if (!*argument || !argument)
		return (-6);
	cmd_plus_args = ft_split(argument, ' ');
	if (!cmd_plus_args)
		perror_and_exit("malloc", NULL);
	if (access(cmd_plus_args[0], F_OK | X_OK) == 0)
	{
		ft_freestr(cmd_plus_args);
		return (0);
	}
	cmd_path = get_path(cmd_plus_args[0], env);
	if (access(cmd_path, F_OK | X_OK) == 0)
	{
		free_cmd_and_path(cmd_plus_args, cmd_path);
		return (0);
	}
	else
	{
		free_cmd_and_path(cmd_plus_args, cmd_path);
		return (-6);
	}
}

// The function checks if the argument is valid. In case it is valid,
// it returns 5. If not it calls the function 'no_cmd_path' and
// 'no_cmd_path' displays the info about invald argument on stderr.
// If a command can be accessed by passing an argument to the access
// function call, then the argument is the path to the command.
int	check_cmd(char *argument, char *env[])
{
	char	**cmd_plus_args;
	char	*cmd_path;

	cmd_plus_args = ft_split(argument, ' ');
	if (!cmd_plus_args)
		print_stderr("malloc");
	if (access(cmd_plus_args[0], F_OK | X_OK) == 0)
	{
		ft_freestr(cmd_plus_args);
		return (5);
	}
	cmd_path = get_path(cmd_plus_args[0], env);
	if (!cmd_path)
	{
		no_cmd_path(cmd_plus_args);
		return (0);
	}
	else
	{
		ft_freestr(cmd_plus_args);
		free(cmd_path);
		return (5);
	}
}
