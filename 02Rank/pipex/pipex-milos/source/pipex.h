/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:44:50 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/19 15:59:13 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <stdio.h>

// main.c
char	**get_paths(char **envp);
void	put_str_exit_num(char *str, int num);

// piping.c
int		go_piping(char **argv, char **envp, char **my_paths);
void	ch1_prc(int *fds, char **argv, char **envp, char **my_paths);
void	ch1_exe(char **argv, char **envp, char **my_paths);
void	ch2_prc(int *fds, char **argv, char **envp, char **my_paths);
void	ch2_exe(char **argv, char **envp, char **my_paths);

// utils.c
char	**get_cmdstrarr(char *cmdandopts);
int		go_wait(pid_t child1, pid_t child2);
int		closer_of_closes(int *fds);
void	perr_n_exit_errno(char *str);
void	perr_n_exit_num(char *str, int num);

// liberators.c
void	free_strarr(char **strarr);
void	fr1_perr_n_exit_errno(char **strarr, char *str);
void	fr1_put_str_exit_num(char **strarr, char *str, int num);

#endif
