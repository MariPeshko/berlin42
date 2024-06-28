/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:11:17 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/28 21:45:52 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

int	child_process(char *argv, char **env, int read_from)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		w_errpipe_close(read_from);
	pid = fork();
	if (pid == -1)
		w_errfork_close(read_from, fd);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		call_cmd(argv, env);
	}
	else
	{
		close(fd[1]);
		dup2(read_from, STDIN_FILENO);
		close(read_from);
		waitpid(pid, NULL, 0);
	}
	return (fd[0]);
}

static void	multi_pipe(int argc, char **argv, char **env)
{
	int		cmd;
	char	mode;
	int		write_to;
	int		read_from;
	
	check_args_multi(argc, argv, env);
	read_from = open_infile(argv[1]);
	w_dup2(read_from, STDIN_FILENO, -2);
	mode = 'p';
	cmd = 2;
	while (cmd < argc - 2)
	{
		read_from = child_process(argv[cmd++], env, read_from);
	}
	write_to = open_outfile(argv[argc - 1], mode);
	w_dup2(write_to, STDOUT_FILENO, read_from);
	call_cmd(argv[argc - 2], env);
}

// The function reads from the standart input with get_next_line
// and writes to the pipe to fd[1]. When the child process reads the LIMITER
// it exit and gives a signal to parent process that it finished successfully.
static int	here_read(char *lim)
{
	int		pip;
	int		id;
	int		fd[2];
	char	*str;
	
	pip = pipe(fd);
	id = fork();
	
	if (id == 0)
	{
		close(fd[0]);
		while (1)
		{
			str = get_next_line(0);
			if (ft_strncmp(str, lim, ft_strlen(lim)) == 0 &&
				str[ft_strlen(lim)] == 10)
			{
				free(str);
				exit(EXIT_SUCCESS);
			}
			write(fd[1], str, ft_strlen(str));
			free(str);
		}
	}
	else
	{
		close(fd[1]);
		// w_dup2(fd[0], STDIN_FILENO, fd[1]);
		waitpid(id, NULL, 0);
		return (fd[0]);
	}
}

static void	here_doc(int argc, char **argv, char **env)
{
	int		cmd;
	char	mode;
	int		write_to;
	int		read_from;

	check_args_hdoc(argc, argv, env);
	read_from = here_read(argv[2]);
	w_dup2(read_from, STDIN_FILENO, -2);
	mode = 'h';
	cmd = 3;
	while (cmd < argc - 2)
		read_from = child_process(argv[cmd++], env, read_from);
	write_to = open_outfile(argv[argc - 1], mode);
	w_dup2(write_to, STDOUT_FILENO, read_from);
	call_cmd(argv[argc - 2], env);
}

int	main(int argc, char **argv, char **env)
{
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
		here_doc(argc, argv, env);
	else
		multi_pipe(argc, argv, env);
}
