
#include "minishell.h"

/**
 * DESRIPTION:
 * in this file the lexer-part of creating a shell (NAME?) is organised
 * 1st it searches for operators (except those in quotes)
 * and adds spaces before and after
 * 2nd it searches for spaces (except those in quotes)
 * and splits the input string from readline into an array of strings
 * 3rd / 4th (?) it integrates variables if listed within a word
 * and deletes the quotes
 * 3rd / 4th it creates an linked list out of the array of strings
 * wich saves command right, command left, value, token (word / operator)
 */

/**
 * @brief function that checks for double operators
 *
 * @param c the first char to search in
 * @param k the second char to search in
 */
static bool	double_operator_check(char c, char k)
{
	if ((c == '<' && k == '<') || (c == '>' && k == '>'))
		return (1);
	else
		return (0);
}

/**
 * @brief function that checks for single operators
 *
 * @param c the char to search in
 */
static bool	single_operator_check(char c)
{
	if ((c == '<') || (c == '>') || (c == '|') //		|| (c == '$')
		|| (c == ';'))
		return (1);
	else
		return (0);
}

/**
 * @brief a helper function for ft_count,
 * it loops through not necessary parts of a string
 * (within quotes)
 * while continuing counting the indexer
 *
 * @param src the string to loop in
 * @param len the indexer to continue counting while iterating
 * @param endsign the sign until the indexer should jump to
 */
static char	*ft_jumper(char *src, int *len, char endsign)
{
	*len = *len + 1;
	src++;
	while (*src && *src != endsign)
	{
		(*len)++;
		src++;
	}
	return (src);
}

/**
 * @brief function that checks for occurence of unquoted operators
 * and calculates extra memory space (len) for adding spaces in
 * between
 *
 * @param src the string to count in
 */
static int	ft_count(char *src)
{
	int		len;
	char	*temp;

	len = 0;
	temp = src;
	while (*temp)
	{
		if (*temp == '\"')
			temp = ft_jumper(temp, &len, '\"');
		else if (*temp == '\'')
			temp = ft_jumper(temp, &len, '\'');
		if (double_operator_check(*temp, *(temp + 1)))
		{
			len += 3;
			temp++;
		}
		// else if (single_operator_check(*temp)) // markus
		else if (single_operator_check(*temp) && (*(temp - 1)) && *(temp
				- 1) != 32)
		{
			len += 2;
		}
		if (*temp)
		{
			len++;
			temp++;
		}
	}
	return (len);
}

/**
 * @brief a helper function for ft_create_clean_input
 * it loops through not necessary parts of a string
 * (within quotes)
 * while continuing copying from src
 * if (src[i] == '\"') || if (src[i] == '\'')
 *
 * @param dest the destination pointer to copy in
 * @param src the source pointer to copy from
 * @param endsign the sign until the indexer should copy to
 */
static void	ft_jump_copy(char **dest, char **src, char endsign)
{
	**dest = **src;
	if (*(*src + 1) == endsign)
	{
		(*dest)++;
		(*src)++;
		**dest = **src;
	}
	else if (*(*src + 1) != '\0')
	{
		(*dest)++;
		(*src)++;
		*(*dest)++ = *(*src)++;
		while (*(*src) && *(*src) != endsign)
			*(*dest)++ = *(*src)++;
		if (*(*src) != '\0')
			**dest = **src;
	}
}

/**
 * @brief a helper function for ft_create_clean_input;
 * it adds spaces before and after operators
 *
 * @param dest the destination string where to integrate additional
 * spaces before an after operators
 * @param src the source string required to create dest
 */

static void	ft_op_separator(char **dest, char **src)
{
	if (double_operator_check(*(*src), *(*src + 1)))
	{
		**dest = ' ';
		(*dest)++;
		**dest = **src;
		(*src)++;
		(*dest)++;
		**dest = **src;
		(*dest)++;
		**dest = ' ';
	}
	else /// (c) changes of Marina
	{
		if (*(*dest - 1) && *(*dest - 1) != 32)
		{
			**dest = ' ';
			(*dest)++;
		}
		**dest = **src;
		if (*(*src + 1) && *(*src + 1) != 32)
		{
			(*dest)++;
			**dest = ' ';
		}
	}
}

/**
 * @brief this function copies from src to dest under certain certain
 * circumstances (unquoted operators have to be seperated by spaces)
 *
 * @param dest the destination string where to copy to
 * @param src the source string where to compy from
 */
static void	ft_create_clean_input(char *dest, char *src)
{
	while (*src)
	{
		if (*src == '\"')
			ft_jump_copy(&dest, &src, '\"');
		else if (*src == '\'')
			ft_jump_copy(&dest, &src, '\'');
		else if (double_operator_check(*src, *(src + 1)))
			ft_op_separator(&dest, &src);
		else if (single_operator_check(*src) && (*src - 1) && (*src - 1) != 32)
		{
			ft_printf("ft_op_separator\n");
			ft_op_separator(&dest, &src);
		}
		else
			*dest = *src;
		if (*src != '\0')
		{
			dest++;
			src++;
		}
	}
	*dest = '\0';
}

/**
 * @brief function that creates a new cleaned input-string
 * with spaces for an after unquoted operators
 *
 * @param src the source string to clean
 * @return src in case there are no operators, otherwise dest_original
 */
static char	*ft_clean_input(char *src)
{
	char	*dest;
	char	*dest_original;
	size_t	len;

	dest = NULL;
	len = ft_count(src);
	ft_printf("malloced len for cleaned input: %i\n", len);
	if (len == (ft_strlen(src)))
	{
		ft_printf("No modification of input required. Delete this message\n");
		return (ft_strdup(src));
	}
	// better to use calloc
	dest = (char *)malloc(sizeof(char) * (len + 1));
	dest_original = dest;
	ft_create_clean_input(dest, src);
	ft_printf("real len of cleaned input: %i\n", ft_strlen(dest_original));
	return (dest_original);
}

/**
 * @brief function that
 * 1st creates an array of strings out of the cleaned input
 * 2nd creates a linked list out of this array of strings --> TO-DO
 *
 * @param readline_str the input of command line read by function readline
 * @return: a linked list with all input keywords or an array of strings???
 */
char	**create_nodes(char *readline_input)
{
	char	*clean_input;
	char	**input_arr;
	char	*extra_input;

	clean_input = NULL;
	input_arr = NULL;
	extra_input = NULL;
	clean_input = ft_clean_input(readline_input);
	if (!clean_input)
	{
		// TODO: error_handling;
		exit(EXIT_FAILURE);
	}
	ft_printf("readline_input:\n%s$$$\n", readline_input);
	ft_printf("%s$$$\nclean_input:\n", clean_input);
	// Here need to be more conditions. Before '|' there must not be
	// another PIPE(s) signs. We could check it before.
	if (is_open_pipe(clean_input)) // |
		extra_input = extra_prompt();
	// if (readline_input[(ft_strlen(readline_input) - 1)] == '|') // |
	// 	extra_input = extra_prompt();
	input_arr = ft_split_quotes(clean_input, ' ');
	free(clean_input);
	clean_input = NULL;
	if (extra_input)
		input_arr = add_extra_input(input_arr, extra_input);
	if (!input_arr)
	{
		// TODO: error_handling;
		exit(EXIT_FAILURE);
	}
	// TO-DO: create a linked list
	return (input_arr);
}
