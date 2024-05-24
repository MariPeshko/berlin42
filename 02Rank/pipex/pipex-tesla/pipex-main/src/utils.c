/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:02:23 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/13 16:08:18 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./pipex.h"

t_pipex	*init_pipex(char **env)
{
	t_pipex	*data;

	data = (t_pipex *) malloc(1 * sizeof(t_pipex));
	data->in_fd = -1;
	data->out_fd = -1;
	data->is_invalid_infile = true;
	data->path = get_path(env);
	data->cmds = ft_calloc(1, sizeof(char *));
	data->cmd_args = NULL;
	data->row_c = 0;
	data->cmd_count = 0;
	data->status = 0;
	return (data);
}

void	print_usage(void)
{
	ft_printf(STDOUT_FILENO, "\nUsage:\t" S_BOLD GREEN "./pipex " BLUE 
		"`INFILE` \"CMD 1\" \"CMD 2\" `OUTFILE`" R "\n\n");
	ft_printf(STDOUT_FILENO, "\t" BLUE "`INFILE`" R
		"\t- Input file for the program.\n");
	ft_printf(STDOUT_FILENO, "\t" BLUE "`OUTFILE`" R
		"\t- Output file for the program.\n");
	ft_printf(STDOUT_FILENO, "\t" BLUE "`CMD 1`" R
		"\t\t- First command to be executed.\n");
	ft_printf(STDOUT_FILENO, "\t" BLUE "`CMD 2`" R
		"\t\t- Second command to be executed.\n\n");
	ft_printf(STDOUT_FILENO, "\n\nHow it looks in "MAGENTA"bash"R":\n\t" );
	ft_printf(STDOUT_FILENO, GREEN S_BOLD 
		"< `INFILE` `CMD1` | `CMD2` > `OUTFILE`" R "\n");
}

char	**get_path(char **env)
{
	char	**paths;

	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
			break ;
		env++;
	}
	paths = ft_split(*env + 5, ':');
	return (paths);
}

void	list_free(char **lst)
{
	int	i;

	if (!lst)
		return ;
	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}

char	*get_bin(char *cmd)
{
	char	*bin;
	char	**cmdv;

	cmdv = ft_split(cmd, ' ');
	if (!cmdv)
		return (NULL);
	bin = ft_strdup(cmdv[0]);
	list_free(cmdv);
	return (bin);
}
