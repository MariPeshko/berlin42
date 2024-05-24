/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:46:18 by mitadic           #+#    #+#             */
/*   Updated: 2023/11/20 15:46:20 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				srclen;
	char			*res;
	unsigned char	smb;

	res = (char *)s;
	smb = c;
	srclen = ft_strlen(s);
	while (srclen != 0 && res[srclen] != smb)
		srclen--;
	if (res[srclen] == smb)
		return (&res[srclen]);
	else
		return (NULL);
}
