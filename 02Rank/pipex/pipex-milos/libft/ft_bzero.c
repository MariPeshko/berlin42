/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:48:47 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/17 12:27:07 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
	return ;
}

/*
#include <strings.h>
#include <stdio.h>
int	main(void)
{
	char	str1[] = "ABDCEFGH";
	char	str2[] = "ABCDEFGH";
	void	*ptr1 = &str1[5];
	void	*ptr2 = &str2[5];
	int	i = 5;

	ft_bzero(ptr1, i);
	bzero(ptr2, i);

	printf("str1 is %s\n", str1);
	printf("str2 is %s\n", str2);
	return (0);
}
*/
