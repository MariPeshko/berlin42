/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:55:54 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/28 15:40:31 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"
#include "libft/libft.h"
//#include "get_next_line.h"

// ft_calloc and ft_bzero
void	*ft_b_calloc(size_t count, size_t size)
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

char	*ft_storage_plus_buffer(char *storage, char *buff)
{
	char	*str;

	str = (char *)ft_b_calloc(ft_strlen(storage) + ft_strlen(buff) + 1,
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
