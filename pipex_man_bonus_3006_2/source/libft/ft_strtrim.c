/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:00:57 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/20 22:00:57 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	char_check(char const *set, char const c)
{
	size_t	i;

	i = 0;
	if (!set)
		return (0);
	while (i < ft_strlen(set))
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*str_new(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	i;

	if (s1 == NULL)
		return (NULL);
	if (!ft_strlen(set) || !ft_strlen(s1) || set == NULL)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (char_check(set, s1[start]) == 1 && s1[start])
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (char_check(set, s1[end - 1]) == 1)
		end--;
	trim = str_new(end - start);
	if (!trim)
		return (NULL);
	i = 0;
	while (start < end)
		trim[i++] = s1[start++];
	trim[i] = '\0';
	return (trim);
}
