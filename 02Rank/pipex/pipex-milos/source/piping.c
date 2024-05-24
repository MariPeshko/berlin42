/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:36:08 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/19 15:44:06 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ch2_exe(char **argv, char **envp, char **my_paths)
{
	int		i;
	char	*cmdpath;
	char	**cmdandopts;

	i = -1;
	cmdandopts = get_cmdstrarr(argv[3]);
	if (!cmdandopts)
		fr1_put_str_exit_num(my_paths, "MallocFail Child2", 2);
	while (my_paths[++i])
	{
		cmdpath = ft_strjoin(my_paths[i], "/sh");
		if (!cmdpath)
		{
			free_strarr(cmdandopts);
			fr1_put_str_exit_num(my_paths, "MallocFail Child2", 2);
		}
		if (access(cmdpath, X_OK) == 0)
			break ;
		free(cmdpath);
	}
	execve(cmdpath, cmdandopts, envp);
	free(cmdpath);
	free_strarr(cmdandopts);
	ft_putstr_fd("Here\n", 2);
}

void	ch2_prc(int *fds, char **argv, char **envp, char **my_paths)
{
	int	outfile_fd;

	outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (outfile_fd < 0)
		fr1_perr_n_exit_errno(my_paths, "open in Child2");
	if (close(fds[1]) < 0)
		fr1_perr_n_exit_errno(my_paths, "close(fds[1]) in Child2");
	if (dup2(fds[0], STDIN_FILENO) < 0)
		fr1_perr_n_exit_errno(my_paths, "dup2 in Child2");
	if (close(fds[0]) < 0)
		fr1_perr_n_exit_errno(my_paths, "close(fds[0]) in Child2");
	if (dup2(outfile_fd, STDOUT_FILENO) < 0)
		fr1_perr_n_exit_errno(my_paths, "dup2 in Child2");
	if (close(outfile_fd) < 0)
		fr1_perr_n_exit_errno(my_paths, "close(outfile_fd) in Child2");
	ch2_exe(argv, envp, my_paths);
	fr1_perr_n_exit_errno(my_paths, "execve in Child2");
}

void	ch1_exe(char **argv, char **envp, char **my_paths)
{
	int		i;
	char	*cmdpath;
	char	**cmdandopts;

	i = -1;
	cmdandopts = get_cmdstrarr(argv[2]);
	if (!cmdandopts)
		fr1_put_str_exit_num(my_paths, "MallocFail Child1", 2);
	while (my_paths[++i])
	{
		cmdpath = ft_strjoin(my_paths[i], "/sh");
		if (!cmdpath)
		{
			free_strarr(cmdandopts);
			fr1_put_str_exit_num(my_paths, "MallocFail Child1", 2);
		}
		if (access(cmdpath, X_OK) == 0)
			break ;
		free(cmdpath);
	}
	execve(cmdpath, cmdandopts, envp);
	free(cmdpath);
	free_strarr(cmdandopts);
}

void	ch1_prc(int *fds, char **argv, char **envp, char **my_paths)
{
	int	infile_fd;

	if (access(argv[1], R_OK) != 0)
		fr1_perr_n_exit_errno(my_paths, "access to infile");
	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd < 0)
		fr1_perr_n_exit_errno(my_paths, "open in Child1");
	if (close(fds[0]) < 0)
		fr1_perr_n_exit_errno(my_paths, "close(fds[0]) in Child1");
	if (dup2(infile_fd, STDIN_FILENO) < 0)
		fr1_perr_n_exit_errno(my_paths, "dup2 in Child1");
	if (close(infile_fd) < 0)
		fr1_perr_n_exit_errno(my_paths, "close(infile_fd) in Child1");
	if (dup2(fds[1], STDOUT_FILENO) < 0)
		fr1_perr_n_exit_errno(my_paths, "dup2 in Child1");
	if (close(fds[1]) < 0)
		fr1_perr_n_exit_errno(my_paths, "close(fds[1]) in Child1");
	ch1_exe(argv, envp, my_paths);
	fr1_perr_n_exit_errno(my_paths, "execve in Child1");
}

int	go_piping(char **argv, char **envp, char **my_paths)
{
	int		fds[2];
	pid_t	child[2];

	if (pipe(fds) < 0)
		fr1_perr_n_exit_errno(my_paths, "pipe");
	child[0] = fork();
	if (child[0] < 0)
		fr1_perr_n_exit_errno(my_paths, "fork");
	if (!child[0])
		ch1_prc(fds, argv, envp, my_paths);
	child[1] = fork();
	if (child[1] < 0)
		fr1_perr_n_exit_errno(my_paths, "fork");
	if (!child[1])
		ch2_prc(fds, argv, envp, my_paths);
	if (!closer_of_closes(fds))
		fr1_perr_n_exit_errno(my_paths, "close(pipe's ends)");
	if (!go_wait(child[0], child[1]))
		fr1_perr_n_exit_errno(my_paths, "waitpid");
	return (1);
}
