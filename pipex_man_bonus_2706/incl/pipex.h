/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 23:22:29 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/27 17:59:35 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h> // open
# include <stdlib.h> // malloc, free, exit, EXIT_FAILURE, access, dup2, execve
# include <unistd.h> // write, read (neeeded?), pipe, fork, unlink
# include <stdio.h> // perror
# include <sys/wait.h> // waitpid, pid_t, WIFEXITED(status)
# include <stddef.h> // for NULL

// checker
void	check_args(int argc, char **argv, char *env[]);
int		check_cmd(char *cmd, char *env[]);
int		check_run_or_not(char *cmd, char *env[]);

// files
int		open_infile(char *name_file);
int		open_outfile(char *name_file);

// retrieve a path to command and execute
void	call_cmd(char *cmd, char *env[]);
char	*get_path(char *cmd_name, char **env);
char	*get_all_folders(const char *env_var_path, char **env);
char	*exe_exists(char **folders, char *cmd_name);
char	*build_cmd_path(const char *folder, const char *cmd_name);

// errors
void	print_stderr(char *what_error);
void	perror_and_exit(char *what_error, int *pipe_fd);
void	no_cmd_path(char **cmd_plus_args);
void	error_file(char *outfile);

// clean up
void	ft_freestr(char **lst);

// wrappers for dup2 and close
void	w_dup2(int dupfd, int newfd, int fd_open);

// bonus functions: checker and wrappers for fork and pipe
void	check_args_bonus(int argc, char **argv, char *env[]);
void	w_errfork_close(int open_fd, int *pipe_fd);
void	w_errpipe_close(int open_fd);

#endif
