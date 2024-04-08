/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:00:39 by astavrop          #+#    #+#             */
/*   Updated: 2023/12/16 19:42:31 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif // !BUFFER_SIZE

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

char		*get_next_line(int fd);
void		*ft_calloc(size_t nmem, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *string);
char		*ft_strchr(const char *string, int c);

#endif
