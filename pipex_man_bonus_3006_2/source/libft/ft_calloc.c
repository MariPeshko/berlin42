/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:17:48 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/21 19:27:13 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr != 0)
		ft_bzero(ptr, count * size);
	return (ptr);
}
/*int	main(void)
{
	int	*p;

	p = ft_calloc(10, sizeof(int));
	for (int i = 0; i < 10; i++)
		p[i] = i * 5;
	for (int i = 0; i < 10; i++)
		printf("%d\n", p[i]);
	return (0);
}*/