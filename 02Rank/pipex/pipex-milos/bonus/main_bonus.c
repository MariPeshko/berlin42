/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:36:14 by mitadic           #+#    #+#             */
/*   Updated: 2024/03/04 12:46:12 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	int		prcs_count;

	prcs_count = argc - 3;
	if (argc < 5)
		put_str_exit_num("Usage: ./prg infl cmd1 ... cmdn outfl\n", 1);
	my_paths = get_paths(envp);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		go_piping_here(prcs_count, argv, my_paths);
	else
		go_piping(prcs_count, argv, my_paths);
	free_strarr(my_paths);
	return (0);
}
