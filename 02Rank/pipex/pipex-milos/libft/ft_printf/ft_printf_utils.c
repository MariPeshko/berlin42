/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:28:19 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/26 15:29:11 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_mod(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr_mod(char *s, int *pflen)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*pflen = *pflen + 6;
		return ;
	}
	while (*s != 0)
	{
		write (1, s, 1);
		*pflen = *pflen + 1;
		s++;
	}
	return ;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}
