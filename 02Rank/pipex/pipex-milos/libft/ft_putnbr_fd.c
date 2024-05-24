/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:03:01 by mitadic           #+#    #+#             */
/*   Updated: 2023/11/24 18:03:05 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == 0)
		write (fd, "0", 1);
	else if (n > -10 && n < 10)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		c = n + 48;
		write (fd, &c, 1);
		return ;
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		if (n < 0)
			c = (n % 10) * -1 + 48;
		else
			c = n % 10 + 48;
		write(fd, &c, 1);
	}
}

/*
int	main(void)
{
	int	n;

	n = -2147483648;
	// n = 0;
	// n = 2147483647;
	ft_putnbr_fd(n, 1);
}
*/
