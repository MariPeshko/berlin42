/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_acces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:23:03 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/19 13:50:14 by mpeshko          ###   ########.fr       */
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


// Extracts the value of a specified environment variable ('env_var_search')
// from the given environment variable array ('env').
// This function is used in 'get_cmd_path' to retrieve the value of 'PATH',
// containing a list of directories where the system searches for executables
// when commands are entered into the CLI.
static	char	*get_env_values(const char *env_var_search, char **env)
{
	size_t	i;
	size_t	len;
	char	*env_var;

	i = 0;
	while (env[i])
	{
		len = 0;
		while (env[i][len] && env[i][len] != '=')
			len++;
		env_var = ft_substr(env[i], 0, len);
		if (!env_var)
			perror_and_exit("malloc", NULL);
		if (ft_strcmp(env_var, env_var_search) == 0)
		{
			free(env_var);
			return (env[i] + len + 1);
		}
		free(env_var);
		i++;
	}
	return (NULL);
}

// Constructs the path to a command executable by concatenating the specified
// directory path and command name.
static char	*construct_cmd_path(const char *directory, const char *cmd_name)
{
	char	*temp;
	char	*cmd_path;

	temp = ft_strjoin(directory, "/");
	if (!temp)
		perror_and_exit("malloc", NULL);
	cmd_path = ft_strjoin(temp, cmd_name);
	free(temp);
	if (!cmd_path)
		perror_and_exit("malloc", NULL);
	return (cmd_path);
}

// Retrieves the system path of the specified command executable ('cmd_name'),
// which is the first occurrence found in the directories listed in the "PATH"
// environment variable (found in 'env').
static char	*get_cmd_path(char *cmd_name, char **env)
{
	size_t	i;
	char	**directories;
	char	*cmd_path;

	i = 0;
	directories = ft_split(get_env_values("PATH", env), ':');
	if (!directories)
		perror_and_exit("malloc", NULL);
	while (directories[i] != NULL)
	{
		cmd_path = construct_cmd_path(directories[i], cmd_name);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			ft_freestr(directories);
			return (cmd_path);
		}
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	ft_freestr(directories);
	return (NULL);
}

static void	no_cmd_path(char **cmd_args)
{
	ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
	ft_putstr_fd(cmd_args[0], STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_freestr(cmd_args);
}

// Executes the specified command ('cmd') along with its arguments, using the
// execve() system call. Before execution, it retrieves the full path to the
// command executable using get_cmd_path(). If the command is not
// found or if execution fails, an appropriate error message is displayed,
// and the program exits with a failure status.
int	check_cmd(char *cmd, char *env[])
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		perror_cmd("malloc");
	if (access(cmd_args[0], F_OK | X_OK) == 0)
		return (5);
    // else
	// {
    //     ft_freestr(cmd_args);
    //     perror_and_exit("access", NULL);
	// }
	cmd_path = get_cmd_path(cmd_args[0], env);
	if (!cmd_path)
	{
		no_cmd_path(cmd_args);
		return (0);
	}
	else
	{
		free(cmd_path);
		ft_freestr(cmd_args);
		return (5);
	}
}
