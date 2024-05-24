/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:46:32 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/07 15:35:29 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./pipex.h"

// Check if the specific command executable exists in the PATH.
char	*check_cmd(char *cmd, char **paths)
{
	char	*path;
	char	*full_path;
	char	*bin;

	bin = get_bin(cmd);
	if (!bin)
		return (NULL);
	if ((ft_strncmp(bin, "./", 2) == 0) && access(bin, X_OK) == 0)
		return (ft_strdup(bin));
	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		full_path = ft_strjoin(path, bin);
		free(path);
		if (access(full_path, X_OK) == 0)
		{
			free(bin);
			return (full_path);
		}
		free(full_path);
		paths++;
	}
	ft_printf(STDERR_FILENO, RED "Command \'%s\' not found." R"\n", cmd);
	free(bin);
	return (NULL);
}

int	insert(char ***array, char *new)
{
	int		i;
	int		j;
	char	**new_array;

	i = 0;
	j = -1;
	while ((*array)[i])
		i++;
	new_array = (char **) malloc((i + 2) * sizeof(char *));
	if (!new_array)
		return (printf_error(RED"[insert]: Memory allocation failed."R"\n", 1));
	while (++j < i)
		new_array[j] = (*array)[j];
	new_array[i] = ft_strdup(new);
	if (!new_array[i])
	{
		free(new_array);
		return (printf_error(RED"[insert]: ft_strdup failed."R"\n", 1));
	}
	new_array[i + 1] = NULL;
	free(*array);
	*array = new_array;
	return (0);
}

int	parse_cmds(int argc, char **argv, t_pipex **data)
{
	int	i;

	i = 2;
	while (i < argc - 1)
	{
		if (insert(&(*data)->cmds, argv[i]) == 1)
			return (printf_error(RED"Error during cmd parsing."R"\n", 1));
		i++;
	}
	return (0);
}
