/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:20:13 by mstracke          #+#    #+#             */
/*   Updated: 2024/08/03 22:44:50 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//to avoid duplications
#ifndef MINISHELL_H
# define MINISHELL_H

//stdio.h (for debugging) | stdlib.h (for malloc & free) | 
//unistd.h (for write) is included in libft.h
# include "../libft/include/libft.h"
//#include <limits.h>
//to use data type bool
# include <stdbool.h>
//to provide a standardized way to report and interpret error conditions
# include <errno.h>
//to be able to work with function waitpid
# include <sys/wait.h>
// to be able to work with function readline
// we also have to include -lreadline to our Makefile 
// to consider readline while compiling
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

//define error message
# define INPUT_ERROR "Not correct number of input arguments to execute minishell\n"

//it is "a good practice" to use a global variable for environment instead of picking it in the main
extern char	**environ;

typedef enum e_tokentype {
    CMD_BUILTIN,
    CMD_EXECUTABLE
} t_tokentype;

typedef struct s_data {
    int infile;       // Input file descriptor (defaults to stdin)
    int outfile;      // Output file descriptor (defaults to stdout)
    char **cmd;       // Command and arguments
    t_tokentype type; // Type of the command
} t_data;

//maybe rename to bin_path for binary path
typedef struct s_envp{
	char	**bin_paths;
	char	***commands;
	char	*outfile;
	char	*infile;
	size_t	commands_no;
}				t_envp;

//required functions from libft
//
//f

// main.c
//
//init.c
//int		init_infile(t_envp *infos, char *infile);
//void	init_compath(t_envp *infos, char **argv, char **paths);
//void	init_outfile(t_envp *infos);
//int		init_check(char **argv, char **paths, t_envp *infos);
//inputcheck.c
//char	*flagcheck(const char *argv);
//int		bin_paths_init(char *command, char **paths, char **bin_paths);
//exec.c
//int		ft_execute(t_envp *infos, char *const envp[]);
// void		ft_execute(t_envp *infos, char *const envp[]);
//utils.c
//size_t	ft_arrlen(char **arr_str);
//void	ft_free(char **arr);
//void	free_struct(t_envp *infos);
//void	error_handling(int err, t_envp *i, int com_no);
void	error_handling(int err);
char	**create_nodes(char *readline_str);
char	**ft_split_quotes(char const *s, char c);

// new
void    parser(char **input_arr);

#endif
