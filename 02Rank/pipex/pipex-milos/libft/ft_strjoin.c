/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:47:19 by mitadic           #+#    #+#             */
/*   Updated: 2024/02/02 12:18:50 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	i = -1;
	j = -1;
	if (s1)
	{
		while (s1[++i])
			dest[i] = s1[i];
	}
	if (s2)
	{
		while (s2[++j])
			dest[i++] = s2[j];
	}
	dest[i] = '\0';
	return (dest);
}

/* og submission 4 libft, updated during gnl by the version above:
 *
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		s1len;
	int		s2len;
	int		i;
	int		j;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	dest = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!s1 || !s2 || !dest)
		return (NULL);
	i = 0;
	j = 0;
	while (i++ < s1len)
		dest[i - 1] = s1[i - 1];
	while (j < s2len)
	{
		dest[i - 1] = s2[j];
		i++;
		j++;
	}
	dest[i - 1] = '\0';
	return (dest);
}
*/
