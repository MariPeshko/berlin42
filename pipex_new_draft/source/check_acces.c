/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_acces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:23:03 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/26 16:28:19 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"
#include <stdio.h>

// Searching the environmental variable 'PATH' and returning a
// pointer to the forst character after '='. It is a pointer to the
// first folder (directory) in a list of many folders.
static char *get_all_folders(const char *env_var_path, char **env)
{
	size_t i;
	size_t len;
	char *current_env_var;

	i = 0;
	while (env[i])
	{
		len = 0;
		while (env[i][len] && env[i][len] != '=')
			len++;
		current_env_var = ft_substr(env[i], 0, len);
		if (!current_env_var)
			perror_and_exit("malloc", NULL);
		if (ft_strcmp(current_env_var, env_var_path) == 0)
		{
			free(current_env_var);
			return (env[i] + len + 1);
		}
		free(current_env_var);
		i++;
	}
	return (NULL);
}

static char *build_cmd_path(const char *folder, const char *cmd_name)
{
	char *temp;
	char *cmd_path;

	temp = ft_strjoin(folder, "/");
	if (!temp)
	{
		print_stderr("malloc");
		return (NULL);
	}
	cmd_path = ft_strjoin(temp, cmd_name);
	free(temp);
	if (!cmd_path)
		print_stderr("malloc");
	return (cmd_path);
}

// Additional function for getting a path to executable.
// If there is no acces to this command_name in any folder
// it frees folders and returns NULL.
static char *exe_exists(char **folders, char *cmd_name)
{
	char	*path;
	int		i;

	i = 0;
	while (folders[i] != NULL)
	{
		path = build_cmd_path(folders[i], cmd_name);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
		//path = NULL;
		i++;
	}
	return (NULL);
}

// It gets the path to the command executable ("cmd name").
// The search takes place in the "PATH" environment variable (found in "env").
char *get_path(char *cmd_name, char **env)
{
	char **folders;
	char *path;
	char *all_folders;

	all_folders = get_all_folders("PATH", env);
	folders = ft_split(all_folders, ':');
	if (!folders)
	{
		print_stderr("malloc");
		return (NULL);
	}
	path = exe_exists(folders, cmd_name);
	if (!path)
	{
		ft_freestr(folders);
		return (NULL);
	}
	else
	{
		ft_freestr(folders);
		return (path);
	}
}

static void no_cmd_path(char **cmd_plus_args)
{
	ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
	ft_putstr_fd(cmd_plus_args[0], STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_freestr(cmd_plus_args);
}
// The function checks if the argument is valid. In case it is valid,
// it returns 5. If not it calls the function 'no_cmd_path'.
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
