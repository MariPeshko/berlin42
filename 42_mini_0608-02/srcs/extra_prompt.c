#include "minishell.h"

/**
 * Counting a new length to allocate memory for the new trimmed string.
 * (c) Maryna
 */
int	count_trim_len(char *str)
{
	char	*temp;
	size_t	new_len;
	int		i;
	int		last;

	temp = str;
	i = 0;
	new_len = 0;
	last = ft_strlen(str) - 1;
	if (last == 0)
		return (1);
	while (temp[i] == 32)
	{
		i++;
		new_len++;
	}
	new_len = ft_strlen(str) - new_len;
	while (temp[last] == 32)
	{
		last--;
		new_len--;
	}
	return (new_len);
	ft_printf("old length: %i\n", ft_strlen(str));
	ft_printf("new length: %i\n", new_len);
}
/**
 * To trim leading and trailing spaces from a string
 * (c) Maryna
 */
void	trim_it(char **str, char **new)
{
	int	last_not_space;
	int	last;
	int	i;
	int	j;

	i = 0;
	j = 0;
	last_not_space = 0;
	last = ft_strlen(*str) - 1;
	while ((*str)[last] == 32)
		last--;
	last_not_space = last;
	while ((*str)[i] == 32)
		i++;
	while (i <= last_not_space)
	{
		(*new)[j] = (*str)[i];
		i++;
		j++;
	}
	(*new)[j] = '\0';
}
/**
 * To trim leading and trailing spaces from a string and then
 * update the original string pointer with the new trimmed string.
 * (c) Marina
 */
void	trim_out_spaces(char **str)
{
	size_t	new_len;
	char	*new;

	new_len = count_trim_len(*str);
	if (new_len == ft_strlen(*str))
		return ;
	new = ft_calloc(new_len + 1, sizeof(char));
	if (!new)
		// memory error;
		return ;
	trim_it(str, &new);
	free(*str);
	*str = new;
}

/**
 * The function checks if there is PIPE in the end of input.
 * It ignores all SPACES in the end of the input.
 * It returns 0 if all input is only one PIPE.
 * (c) Marina
 */
int	is_open_pipe(char *clean_input)
{
	int	i;

	i = ft_strlen(clean_input) - 1;
	if (i == 0)
		return (0);
	else
		while (clean_input[i] && clean_input[i] == 32)
			i--;
	if (clean_input[i] == '|' && clean_input[i - 1] != '|')
		return (1);
	else
		return (0);
}

/**
 * The function open a prompt in case when in the end the PIPE sign.
 * It implements behaviour of a bash that is waiting for additional input.
 * (c) Marina
 */
char	*extra_prompt(void)
{
	char	*prompt;
	char	*input2;

	prompt = ft_strdup(">");
	input2 = readline(prompt);
	while (!*input2)
	{
		if (!input2)
			exit(EXIT_FAILURE);
		input2 = readline(prompt);
	}
	free(prompt);
	return (input2);
}

//#include <string.h>

/**
 * The function concatenates extra input to main input.
 *
 * @return: array of strings with all concatenated input.
 */
// free(): invalid next size (fast)
// zsh: IOT instruction (core dumped)
// when I have "input_arr" as an array of 2 strings
char	**add_extra_input(char **input_arr, char *extra_input)
{
	int i;
	char **new_input;
	int count;

	i = 0;
	count = 0;
	if (extra_input == NULL)
		return (input_arr);
	while (input_arr[count] != NULL)
		count++;
	ft_printf("count: %i\n", count);
	new_input = ft_calloc(count + 2, sizeof(char *));
	if (!new_input)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	while (i < count)
	{
		// new_input[i] = strdup(input_arr[i]);
		new_input[i] = ft_strdup(input_arr[i]);
		i++;
	}
	// new_input[i] = strdup(extra_input);
	new_input[i] = ft_strdup(extra_input);
	i++;
	new_input[i] = NULL;
	ft_free(input_arr);
	return (new_input);
}