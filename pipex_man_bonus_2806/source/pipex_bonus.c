/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:11:17 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/28 17:36:16 by mpeshko          ###   ########.fr       */
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

	fprintf(stderr, "read_from %i\n", read_from);
	fprintf(stderr, "pipe: %i %i\n", fd[0], fd[1]);
	
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

/* Function who make a child process that will read from the stdin with
 get_next_line until it find the limiter word and then put the output inside a
 pipe. The main process will change his stdin for the pipe file descriptor. */
/*void	here_doc(char *limiter, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*line;
	int		*fd;
	int		pip;
	char	*str;
	pid_t	id;

	if (argc < 6)
		usage();
	if (pipe(fd) == -1)
		error();
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}*/

// ./pipex here_doc LIMITER cmd cmd1 file
// cat << LIM | wc >> file

// The function reads from the standart input with get_next_line
// and writes to the pipe to fd[1]. When the child process reads the LIMITER
// it exit and gives a signal to parent process that it finished successfully.
int	here_doc(char *lim)
{
	int		pip;
	int		id;
	int		fd[2];
	char	*str;
	int		lim_len;

	lim_len = ft_strlen(lim);
	pip = pipe(fd);
	id = fork();
	if (id == 0)
	{
		while (1)
		{
			close(fd[0]);
			str = get_next_line(0);
			if (ft_strncmp(str, lim, ft_strlen(lim)) == 0 &&
				str[lim_len] == 10)
				exit(EXIT_SUCCESS);
			write(fd[1], str, ft_strlen(str));
		}
	}
	else
	{
		close(fd[1]);
		//w_dup2(fd[0], STDIN_FILENO, fd[1]);
		waitpid(id, NULL, 0);
		return (fd[0]);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	cmd;
	int	write_to;
	int	read_from;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		cmd = 3;
		read_from = here_doc(argv[2]);
		w_dup2(read_from, STDIN_FILENO, -2);
	}
	else
	{
		check_args_bonus(argc, argv, env);
		cmd = 2;
		read_from = open_infile(argv[1]);
		w_dup2(read_from, STDIN_FILENO, -2);
	}

	// char buffer[1024];
    // ssize_t bytesRead;

	// while ((bytesRead = read(read_from, buffer, sizeof(buffer))) > 0) {
    //         fwrite(buffer, 1, bytesRead, stderr);
	// }
	// close(read_from);
	
	while (cmd < argc - 2)
	{
		read_from = child_process(argv[cmd++], env, read_from);
		if (read_from == -1)
			exit(EXIT_FAILURE);
	}
	write_to = open_outfile(argv[argc - 1]);
	w_dup2(write_to, STDOUT_FILENO, read_from);
	call_cmd(argv[argc - 2], env);
}
