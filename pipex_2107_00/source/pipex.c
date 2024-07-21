/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:11:17 by mpeshko           #+#    #+#             */
/*   Updated: 2024/07/21 17:19:29 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"

void	last_child(char *argv, char **env, child_return *ch, int write_to)
{
	pid_t		pid;
	int			fd[2];
	t_id_list	*node;

	if (pipe(fd) == -1)
		w_errpipe_close(ch->fd_to_read);
	pid = fork();
	if (pid == -1)
		w_errfork_close(ch->fd_to_read, fd);
	if (pid == 0)
	{
		close(fd[0]);
		w_dup2(write_to, STDOUT_FILENO, -2);
		close(write_to);
		if (!*argv)
			exit(EXIT_FAILURE);
		call_cmd(argv, env);
	}
	else
	{
		node = node_birth(pid);
		list_birth(&ch->list, node);
		close(fd[1]);
		dup2(ch->fd_to_read, STDIN_FILENO);
		close(ch->fd_to_read);
	}
}

void	child_process(char *argv, char **env, child_return **ch)
{
	pid_t		pid;
	int			fd[2];
	t_id_list	*node;

	if (pipe(fd) == -1)
		w_errpipe_close((*ch)->fd_to_read);
	pid = fork();
	if (pid == -1)
		w_errfork_close((*ch)->fd_to_read, fd);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		if (!*argv)
			exit(EXIT_FAILURE);
		call_cmd(argv, env);
	}
	else
	{
		node = node_birth(pid);
		list_birth(&(*ch)->list, node);
		close(fd[1]);
		dup2((*ch)->fd_to_read, STDIN_FILENO);
		close((*ch)->fd_to_read);
		(*ch)->fd_to_read = fd[0];
	}
}

// If no access to infile, then we start execution not from the 1st
// command, but from the 2nd command. This is a behaviour of bash.
static int	cmd_to_start(char *name_file)
{
	int	file_in;

	file_in = open(name_file, O_RDONLY);
	if (access(name_file, R_OK) != 0)
		return (3);
	else
	{
		close(file_in);
		return (2);
	}
}
// static int	w_waitpid(child_return **ch)
// {
// 	child_return *tmp;

// 	fprintf(stderr, "before id: %i\n", (*ch)->list->id);
// 	if (!*ch)
// 		return (-3);
// 	tmp = *ch;
// 	while (tmp->list)
// 	{
// 		waitpid(tmp->list->id, NULL, 0);
// 		fprintf(stderr, "tmp id: %i\n", tmp->list->id);
// 		fprintf(stderr, "inside while\nid: %i\n", (*ch)->list->id);
// 		tmp->list = (*ch)->list->next;
// 	}
// 	//fprintf(stderr, "id: %i\n", (*ch)->list->id);
// 	return(0);
// }

static int	w_waitpid(child_return **ch)
{
	t_id_list *tmp;

	fprintf(stderr, "before id: %i\n", (*ch)->list->id);
	if (!*ch)
		return (-3);
	tmp = (*ch)->list;
	while (tmp)
	{
		waitpid(tmp->id, NULL, 0);
		fprintf(stderr, "tmp id: %i\n", tmp->id);
		fprintf(stderr, "inside while\nid: %i\n", (*ch)->list->id);
		tmp = tmp->next;
	}
	fprintf(stderr, "id: %i\n", (*ch)->list->id);
	return(0);
}

void	multi_pipe(int argc, char **argv, char **env)
{
	int	cmd;
	int	read_from;
	int	write_to;
	child_return *ch;
	
	check_args_multi(argc, argv, env);
	read_from = open_infile(argv[1]);
	w_dup2(read_from, STDIN_FILENO, -2);
	ch = ft_calloc(1, sizeof(child_return));
	ch->fd_to_read = read_from;
	cmd = cmd_to_start(argv[1]);
	while (cmd < argc - 2)
	{
		if (acces_cmd(argv[cmd], env) == -6)
			ch->fd_to_read = dev_null(ch->fd_to_read);
		else
			child_process(argv[cmd], env, &ch);
		cmd++;
	}
	write_to = open_outfile(argv[argc - 1], 'p');
	last_child(argv[cmd], env, ch, write_to);
	
	int tmp;
	
	tmp = w_waitpid(&ch);
	
	// while (ch->list)
	// {
	// 	fprintf(stderr, "1st ch: %i\n", ch->list->id);
	// 	ch->list = ch->list->next;
	// }
	free_struct(&ch);
}

int	main(int argc, char **argv, char **env)
{
	if (argc < 5)
		how_execute_pipex();
	else if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
		here_doc(argc, argv, env);
	else
		multi_pipe(argc, argv, env);
	return (0);
}
