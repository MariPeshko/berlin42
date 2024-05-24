/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:12:29 by mpeshko           #+#    #+#             */
/*   Updated: 2024/05/24 12:26:12 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> // open
# include <stdlib.h> // malloc, free, exit, EXIT_FAILURE, ... and new! - access, dup2, execve
# include <unistd.h> // write, read (neeeded?), pipe, fork, unlink
// and POSIX standard names for file descriptors i.e. STDIN_FILENO
# include <stdio.h> // perror
# include <string.h> // strerror
# include <errno.h> // errno
# include <sys/wait.h> // waitpid, pid_t, WIFEXITED(status)
# include <stddef.h> // for NULL in ft_freestr.c

void	pipeline_left(char **argv, char **env, int *pipe_ends);
void	pipeline_right(char **argv, char **env, int *pipe_ends);
void	call_cmd(char *cmd, char *env[]);
void	perror_and_exit(char *msg, int *pipe_ends);
void	parent_process(int process_id_1, int process_id_2, int *pipe_ends);

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
int     ft_strcmp(const char *s1, const char *s2);
void	ft_freestr(char **lst);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);

#endif