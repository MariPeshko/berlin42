/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:02:51 by mitadic           #+#    #+#             */
/*   Updated: 2023/11/24 18:02:54 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s != 0)
	{
		write (fd, s, 1);
		s++;
	}
	write (fd, "\n", 1);
	return ;
}

/*
int     main(void)
{       
        int     fd = 1;
        char    *str = "This is a string.";
        ft_putendl_fd(str, fd);
        return (0);
}               
*/
