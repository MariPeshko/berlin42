/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:44:50 by mitadic           #+#    #+#             */
/*   Updated: 2024/03/04 12:34:46 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <stdio.h>

// main_bonus.c
int		main(int argc, char **argv, char **envp);
char	**get_paths(char **envp);
void	put_str_exit_num(char *str, int num);

// piping_bonus.c
void	go_piping(int prcs_count, char **argv, char **my_paths);
void	prep(int (*fds)[2], int prcs_count, pid_t **child, char **my_paths);
void	fork_one(int i, pid_t *child, char **my_paths, char *errmsg);

// here_doc.c
void	go_piping_here(int prcs_count, char **argv, char **my_paths);
int		prompt_and_pass(int *fds, char *limiter);

// here_childrenouter_bonus.c
void	ch1_here(int (*fds)[2], char **argv, pid_t *child, char **my_paths);
void	ch1_prc_here(int *fds, char **argv, pid_t *child, char **my_paths);
void	ch_last_here(int *fds, char **argv, pid_t *child, char **my_paths);
void	ch_last_exe_here(char *argv, char **my_paths);

// childrenouter_bonus.c
void	ch1_ctrl(int (*fds)[2], char **argv, pid_t *child, char **my_paths);
void	ch1_prc(int *fds, char **argv, pid_t *child, char **my_paths);
void	ch1_exe(char **argv, char **my_paths);
void	ch_last_prc(int *fds, char **argv, pid_t *child, char **my_paths);
void	ch_last_exe(char *argv, char **my_paths);

// childrenmid_bonus.c
int		reuse_pipe(int i, int prcs_count, int (*fds)[2]);
void	ch_mid_prc(int *pipein, int *pipeout, char *cmd, char **my_paths);
void	ch_mid_exe(char *cmd, char **my_paths);

// utils_bonus.c
char	*crt_cmdpath(char *path, char *cmd);
void	pipe_closer(int count, int (*fds)[2]);
void	close_all_pipeends(int (*fds)[2]);
void	go_wait(int prcs_count, pid_t *child, char **my_paths);
int		go_malloc_int(int count, int **arr);

// liberators_bonus.c
void	purge_waiter(pid_t *wpid, int *status, char **my_paths, pid_t *child);
void	free_strarr(char **strarr);
void	fr1_perr_n_exit_errno(char **strarr, char *str);
void	fr2_perr_n_exit_errno(char **strarr1, char **strarr2, char *str);
void	fr1_put_str_exit_num(char **strarr, char *str, int num);
void	free4exefail(char **strarr, pid_t *child, char *str);
void	free4exefail_noerr(char **strarr, pid_t *child);

#endif
