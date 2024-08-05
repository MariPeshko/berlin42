#include "minishell.h"

// file does not exists
// permissions denied
int	open_file(char *input_file)
{
	int	fd_in;

	fd_in = open(input_file, O_RDONLY);
	if (fd_in == -1)
		return (-2);
	return (fd_in);
}

int input(char **navigator)
{
	int i = 0;

	if (*navigator == NULL)
		return (-1);
	while (navigator[i])
	{
		// if (!ft_strncmp(*navigator, "|", 1))
		if (ft_strncmp(navigator[i], "<", 1) == 0)
			{
				if (navigator[i + 1] != NULL && ft_strncmp(navigator[i + 1], "|", 1) != 0)
					return (open_file(navigator[i + 1]));
				else
					return (-3);
			}
		else
			i++;
	}
	return (0);
}

void parser(char **input_arr)
{
	t_data *one;

	one = ft_calloc(1, sizeof(t_data));
	one->infile = input(input_arr);
	ft_printf("one->infile: %d\n", one->infile);
	if (one->infile == 0)
		ft_printf("Input is standart input\n");
	if (one->infile == -3)
		ft_printf("-bash: syntax error near unexpected token [options]\n");
	if (one->infile == -2)
		{ft_printf("[after <]: No such file or directory\n");
		ft_printf("OR ");
		ft_printf("[after <]: : Permission denied\n");}
	if(one->infile > 0)
		close(one->infile);
	free(one);
}