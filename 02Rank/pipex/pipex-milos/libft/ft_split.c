/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:03:42 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/17 11:47:06 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (i == 0 && s[i] != c)
			count++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

void	*liberate(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	*get_word(char const *s, int start, int end, char **ptr)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (liberate(ptr));
	else
		ft_memset(word, 0, ((end - start + 1) * sizeof(char)));
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**mainbrain(char **ptr, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] != 0)
	{
		if ((i == 0 && s[i] != c) || (i > 0 && s[i] != c && \
					s[i - 1] == c))
		{
			j = i;
			while (s[j + 1] != 0 && s[j + 1] != c)
				j++;
			ptr[count] = get_word(s, i, (j + 1), ptr);
			count++;
			i = j;
		}
		i++;
	}
	ptr[count] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	count;

	if (!s || !ft_isascii(c))
		return (NULL);
	count = word_count(s, c);
	ptr = malloc((count + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	ptr = mainbrain(ptr, s, c);
	return (ptr);
}

/*
#include <stdio.h>
int     main(void)
{
        char    *str = "Tis a string to test.";
	char	*str2 = " a Mu	ch \n we ird	er string  ";
        unsigned char   c = 32; 
	int	i = 0;
        char    **dest = ft_split(str, c);
	char	**dest2 = ft_split(str2, c);

        while (dest[i]) 
        {
                printf("str word is: %s\n", dest[i]);
		free(dest[i]);
                i++;
        }
	i = 0;
	while (dest2[i])
	{
		printf("str2 word is: %s\n", dest2[i]);
		free(dest2[i]);
		i++;
	}
	free(dest);
	free(dest2);
	return (0);
}
*/
