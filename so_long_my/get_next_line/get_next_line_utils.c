/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:06:55 by mpeshko           #+#    #+#             */
/*   Updated: 2024/04/08 13:54:52 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ft_calloc and ft_bzero
void	*ft_calloc_bzero(size_t count, size_t size)
{
	void	*ptr;
	char	*str;
	size_t	total_size;
	size_t	i;

	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	str = (char *)ptr;
	i = 0;
	while (i < total_size)
	{
		str[i] = '\0';
		i++;
	}
	return (ptr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	lensrc;
	size_t	lendst;
	size_t	total_len;
	size_t	i;
	size_t	j;

	i = 0;
	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	j = lendst;
	if (n > lendst)
		total_len = lendst + lensrc;
	else
		total_len = lensrc + n;
	while (src[i] && j + 1 < n)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (total_len);
}

char	*ft_storage_plus_buffer(char *storage, char *buff)
{
	char	*str;

	str = (char *)ft_calloc(ft_strlen(storage) + ft_strlen(buff) + 1,
			sizeof(char));
	if (!str)
	{
		free(storage);
		return (NULL);
	}
	ft_strlcat(str, storage, ft_strlen(storage) + ft_strlen(buff) + 1);
	ft_strlcat(str, buff, ft_strlen(storage) + ft_strlen(buff) + 1);
	free(storage);
	return (str);
}

/*
Finds a specific character in a string and returns a pointer pointing to
its first occurrence, returns NULL if the character is not found.
*/

/*char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}*/
