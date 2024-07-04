/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:12:49 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/27 18:00:55 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

void	check_args_bonus(int argc, char **argv, char *env[])
{
	int	i;

	i = 2;
	if (argc < 6)
	{
		write(STDERR_FILENO, "Your program will be executed like this\n", 41);
		ft_putstr_fd("> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	while (i != argc - 1)
	{
		check_cmd(argv[i], env);
		i++;
	}
	i = 2;
	while (i != argc - 1)
	{
		check_run_or_not(argv[i], env);
		i++;
	}
}
