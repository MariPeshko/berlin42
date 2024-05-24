/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:47:54 by astavrop          #+#    #+#             */
/*   Updated: 2024/02/22 20:25:32 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define R			"\x1b[0m"

# define BLACK		"\x1b[30m"
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define WHITE		"\x1b[37m"

# define B_BLACK	"\x1b[40m"
# define B_RED		"\x1b[41m"
# define B_GREEN	"\x1b[42m"
# define B_YELLOW	"\x1b[43m"
# define B_BLUE		"\x1b[44m"
# define B_MAGENTA	"\x1b[45m"
# define B_CYAN		"\x1b[46m"
# define B_WHITE	"\x1b[47m"

# define S_BOLD			"\x1b[1m"
# define S_ITALIC		"\x1b[3m"
# define S_UNDERLINE	"\x1b[4m"

# define DEV_NULL "/dev/null"

# include "libft.h"
# include "ft_printf.h"
# include <stddef.h>

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef struct s_pipex
{
	int			status;
	int			in_fd;
	int			out_fd;
	t_bool		is_invalid_infile;
	char		**path;
	char		**cmds;
	char		***cmd_args;
	int			row_c;
	int			cmd_count;
}	t_pipex;

typedef struct s_pip
{
	int			in_pipe[2];
	int			out_pipe[2];
}	t_pip;

/* checks */

int			check_input(int argc, char **argv, t_pipex **data);

/* error handling */

int			print_error(char *msg, int code);
int			printf_error(char *msg, int code);
void		destroy(t_pipex **data);
int			end(t_pipex **data, int code); // in pipex.c
int			pend(int pipe[2], t_pipex **data, int code); // in pipex.c

/* parse files */

int			parse_fd(int argc, char **argv, t_pipex **data);

/* parse cmds */

int			parse_cmds(int argc, char **argv, t_pipex **data);
char		*check_cmd(char *cmd, char **paths);

/* parse args */

int			parse_args(char **argv, t_pipex **data);

/* utils */

void		list_free(char **lst);
char		*get_bin(char *cmd);
void		print_usage(void);
t_pipex		*init_pipex(char **env);
char		**get_path(char **env);

/* execute */

int			exec_first(t_pipex **data, char **env, int pipefd[2]);
int			exec_last(t_pipex **data, char **env, int pipefd[2]);

#endif // !PIPEX_H
