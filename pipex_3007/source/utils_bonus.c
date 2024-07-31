/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:12:49 by mpeshko           #+#    #+#             */
/*   Updated: 2024/07/22 12:18:05 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

void	how_execute_pipex(void)
{
	ft_putstr_fd("Hi, human! Input for execution the pipex:\n",
		STDERR_FILENO);
	ft_putstr_fd("\nMANDATORY PART\n", STDERR_FILENO);
	ft_putstr_fd("./pipex file1 cmd1 | cmd2 > file2\n", STDERR_FILENO);
	ft_putstr_fd("\nBONUS\n", STDERR_FILENO);
	ft_putstr_fd("Multipies:\n./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n",
		STDERR_FILENO);
	ft_putstr_fd("Support « and »\n./pipex here_doc LIMITER cmd cmd1 file\n",
		STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	check_args_hdoc(int argc, char **argv, char *env[])
{
	int	i;

	i = 3;
	if (argc != 6)
	{
		ft_putstr_fd("Hi, human! Input for execution here_doc:\n",
			STDERR_FILENO);
		ft_putstr_fd("> ./pipex_bonus here_doc LIMITER cmd cmd1 file\n",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	while (i != argc - 1)
	{
		if (!*argv[i])
			err_empty_arg();
		else
			check_cmd(argv[i], env);
		i++;
	}
}

void	check_args_multi(int argc, char **argv, char *env[])
{
	int	i;

	i = 2;
	if (argc < 5)
	{
		ft_putstr_fd("Hi, human! Input for execution here_doc:\n",
			STDERR_FILENO);
		ft_putstr_fd("> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	while (i != argc - 1)
	{
		if (!*argv[i])
			err_empty_arg();
		else
			check_cmd(argv[i], env);
		i++;
	}
}

int	w_waitpid(child_return **ch)
{
	t_id_list *tmp;

	if (!*ch)
		return (-3);
	tmp = (*ch)->list;
	while (tmp)
	{
		waitpid(tmp->id, NULL, 0);
		tmp = tmp->next;
	}
	return(0);
}
