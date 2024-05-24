/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:36:14 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/19 15:58:59 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	put_str_exit_num(char *str, int num)
{
	if (!str)
		return ;
	ft_putstr_fd(str, 2);
	exit(num);
}

char	**get_paths(char **envp)
{
	int		i;
	char	*pathstring;
	char	**paths;

	i = -1;
	pathstring = NULL;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			pathstring = &envp[i][5];
			break ;
		}
	}
	if (!pathstring)
		put_str_exit_num("'PATH=' not found in env\n", 2);
	paths = ft_split(pathstring, ':');
	if (!paths)
		put_str_exit_num("Memory allocation failed\n", 3);
	return (paths);
}

int	main(int argc, char **argv, char **envp)
{
	char	**my_paths;

	if (argc != 5)
		put_str_exit_num("Usage: ./pipex infl cmd1 cmd2 outfl\n", 1);
	my_paths = get_paths(envp);
	if (!go_piping(argv, envp, my_paths))
		return (1);
	free_strarr(my_paths);
	return (0);
}
