/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:56:24 by mitadic           #+#    #+#             */
/*   Updated: 2023/11/27 11:42:21 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	len;
	void	*dest;

	if (size > 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	len = nmemb * size;
	dest = malloc(len);
	if (!dest)
		return (NULL);
	ft_memset(dest, 0, len);
	return (dest);
}
