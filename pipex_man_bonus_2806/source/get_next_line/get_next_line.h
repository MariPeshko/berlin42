/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:56:18 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/28 15:02:39 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h> // malloc(), free()
# include <unistd.h> // read()
# include <stddef.h> // size_t
# include <fcntl.h>

void	*ft_b_calloc(size_t count, size_t size);
char	*ft_storage_plus_buffer(char *storage, char *buff);
char	*read_until_newline_or_eof(int fd, char *storage);
char	*ft_extract_line(char *storage);
char	*ft_trim_until_newline(char *storage);
char	*get_next_line(int fd);

#endif
