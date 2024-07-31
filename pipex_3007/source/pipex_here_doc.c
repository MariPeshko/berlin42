/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:31:03 by mpeshko           #+#    #+#             */
/*   Updated: 2024/07/30 19:43:49 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

static void	here_read_helper(int write_end, char *lim)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (ft_strncmp(str, lim, ft_strlen(lim)) == 0
			&& str[ft_strlen(lim)] == 10)
		{
			free(str);
			exit(EXIT_SUCCESS);
		}
		write(write_end, str, ft_strlen(str));
		free(str);
	}
}

// The function reads from the standart input with get_next_line
// and writes to the pipe to fd[1]. When the child process reads the LIMITER
// it exit and gives a signal to parent process that it finished successfully.
static int	here_read(char *lim)
{
	int		pip;
	int		id;
	int		fd[2];

	pip = pipe(fd);
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		here_read_helper(fd[1], lim);
	}
	close(fd[1]);
	waitpid(id, NULL, 0);
	return (fd[0]);
}

// mode 'h' is a APPEND mode for outfile
// cmd is '3' because in input the forth argument is a first command
void	here_doc(int argc, char **argv, char **env)
{
	int		cmd;
	char	mode;
	int		write_to;
	int		read_from;
    struct child_return *ch;

    check_args_hdoc(argc, argv, env);
	read_from = here_read(argv[2]);
	w_dup2(read_from, STDIN_FILENO, -2);
	ch = ft_calloc(1, sizeof(child_return));
	if (ch == NULL)
		error_mall_exit(5);
    ch->fd_to_read = read_from;
	mode = 'h';
	cmd = 3;
	while (cmd < argc - 2)
	{
		if (acces_cmd(argv[cmd], env) == -6)
			ch->fd_to_read = dev_null(ch->fd_to_read);
		else
			child_process(argv[cmd], env, &ch);
		cmd++;
	}
	write_to = open_outfile(argv[argc - 1], mode);
    last_child(argv[cmd], env, &ch, write_to);
    if(ch->list != NULL)
		w_waitpid(&ch);
	free_struct(&ch);
}
