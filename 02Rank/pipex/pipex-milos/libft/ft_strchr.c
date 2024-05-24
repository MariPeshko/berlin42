/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:46:12 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/17 12:29:12 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	smb;

	smb = (unsigned char)c;
	while (*s != '\0' && *s != smb)
		s++;
	if (*s == smb)
		return ((char *)s);
	else
		return (NULL);
}
