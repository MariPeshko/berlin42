/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:55:22 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/29 14:36:58 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"
#define BUFFER_SIZE 5

char	*read_until_newline_or_eof(int fd, char *storage)
{
	int		bytes;
	char	*buff;

	if (!storage)
		storage = (char *)ft_b_calloc(1, sizeof(char));
	buff = (char *)ft_b_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(storage);
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		storage = ft_storage_plus_buffer(storage, buff);
		if (ft_strchr(storage, '\n'))
			break ;
	}
	free(buff);
	return (storage);
}

char	*ft_extract_line(char *storage)
{
	char	*extracted_line;
	int		i;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] != '\n' && storage[i])
		i++;
	extracted_line = (char *)ft_b_calloc(i + 2, sizeof(char));
	if (!extracted_line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		extracted_line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		extracted_line[i] = storage[i];
	extracted_line[i + 1] = '\0';
	return (extracted_line);
}

char	*ft_trim_until_newline(char *storage)
{
	char	*upd_storage;
	int		i;

	i = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (storage[i] == '\0')
	{
		free(storage);
		return (NULL);
	}
	upd_storage = ft_substr(storage, (i + 1), (ft_strlen(storage) - i - 1));
	if (upd_storage[0] == '\0')
	{
		free(upd_storage);
		free(storage);
		return (NULL);
	}
	free(storage);
	return (upd_storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (storage != NULL)
			free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = read_until_newline_or_eof(fd, storage);
	if (!storage)
	{
		storage = NULL;
		return (NULL);
	}
	line = ft_extract_line(storage);
	storage = ft_trim_until_newline(storage);
	return (line);
}
