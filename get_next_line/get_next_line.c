/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:06:12 by mpeshko           #+#    #+#             */
/*   Updated: 2024/02/15 20:06:20 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	while (s[i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*read_until_newline_or_eof(int fd, char *storage)
{
	int		bytes;
	char	*buff;

	if (!storage)
		storage = (char *)ft_calloc(1, sizeof(char));
	buff = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(storage, '\n') && bytes != 0)
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
	extracted_line = (char *)ft_calloc(i + 2, sizeof(char));
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
		return (NULL);
	}
	storage = read_until_newline_or_eof(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_extract_line(storage);
	storage = ft_trim_until_newline(storage);
	return (line);
}
/* #include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *line;
	int fd;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("line1: %s", line);
	free(line);

	line = get_next_line(fd);
	printf("line2: %s", line);
	free(line);

	line = get_next_line(fd);
	printf("line3: %s", line);
	free(line);

	line = get_next_line(fd);
	printf("line4: %s", line);
	free(line);

	line = get_next_line(fd);
	printf("line5: %s", line);
	free(line);

	line = get_next_line(fd);
	printf("line6: %s", line);
	free(line);

	line = get_next_line(fd);
	printf("line7: %s", line);
	free(line);

	close(fd);
	return (0);
} */
/* int	main(void)
{
	char *line;
	int i;
	
	i = 1;
	while (1)
	{
		line = get_next_line(0);
		printf("line%i: %s", i, line);
		free(line);
		i++;
	}
} */
