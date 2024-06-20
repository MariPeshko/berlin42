/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:12:29 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/09 18:57:22 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> // open
# include <stdlib.h> // malloc, free, exit, EXIT_FAILURE, access, dup2, execve
# include <unistd.h> // write, read (neeeded?), pipe, fork, unlink
# include <stdio.h> // perror
# include <string.h> // strerror
# include <errno.h> // errno
# include <sys/wait.h> // waitpid, pid_t, WIFEXITED(status)
# include <stddef.h> // for NULL in ft_freestr.c

void	pipeline_left(char **argv, char **env, int *pipe_ends);
void	pipeline_right(char **argv, char **env, int *pipe_ends);
void	call_cmd(char *cmd, char *env[]);
void	perror_and_exit(char *msg, int *pipe_ends);
void	parent_process(int child_id_1, int child_id_2, int *pipe_ends, int n);

int		ft_strcmp(const char *s1, const char *s2);
void	ft_freestr(char **lst);
void	ft_putstr_fd(char *s, int fd);

// checker
int		check_cmd(char *cmd, char *env[]);
int		check_run_or_not(char *cmd, char *env[]);

// bonus
void	pipeline_middle(char *argv, char **env, int *pipe_ends);

#endif
