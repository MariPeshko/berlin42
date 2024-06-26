/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_acces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:23:03 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/26 23:14:16 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"
#include <stdio.h>

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

// This function checks for the number of arguments. If there are less than
// two arguments, then a message is output to the standard error and the
// program exit. Next, in function call 'check_cmd' each argument is checked
// in order (except the last one, the last argument can be an output file.)
// It checks if the arguments are existing commands. Next, in function call
// 'check_run_or_not', the function is checking if the program continues or
// not. If any of command-argument is not vald, the program exits.
void check_args(int argc, char **argv, char *env[])
{
	int i;

	i = 1;
	if (argc < 5)
	{
		write(STDERR_FILENO, "Your program will be executed like this\n", 41);
		ft_putstr_fd("> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file\n",
					 STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	while (argv[++i + 1] != NULL)
		check_cmd(argv[i], env);
	i = 1;
	while (argv[++i + 1] != NULL)
		check_run_or_not(argv[i], env);
}
