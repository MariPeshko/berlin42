/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:23:25 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/27 16:21:13 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

static void	error_permission(char *name_file)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(name_file, STDERR_FILENO);
	ft_putstr_fd(": Permission denied", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	open_infile(char *name_file)
{
	int	file_in;

	file_in = open(name_file, O_RDONLY);
	if (access(name_file, R_OK) != 0)
		error_permission(name_file);
	if (file_in == -1)
	{
		error_file(name_file);
		exit(EXIT_FAILURE);
	}
	else
		return (file_in);
}

int	open_outfile(char *name_file)
{
	int	file_out;

	file_out = open(name_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (access(name_file, W_OK) != 0)
		error_permission(name_file);
	if (file_out == -1)
	{
		error_file(name_file);
		return (-2);
	}
	else
		return (file_out);
}
