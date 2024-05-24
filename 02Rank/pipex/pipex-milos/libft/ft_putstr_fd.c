/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:03:17 by mitadic           #+#    #+#             */
/*   Updated: 2023/11/24 18:03:20 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != 0)
	{
		write (fd, s, 1);
		s++;
	}
	return ;
}

/*
int	main(void)
{
	int	fd = 1;
	char	*str = "This is a string.";
	ft_putstr_fd(str, fd);
	return (0);
}
*/
