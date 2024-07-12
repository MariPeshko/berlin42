/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:22:40 by mpeshko           #+#    #+#             */
/*   Updated: 2023/12/21 21:35:37 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*void	uppercase(unsigned int index, char *ch)
{
	index++;
	*ch = toupper(*ch);
}

int	main(void)
{
	char	str[] = "lowercase";

	ft_striteri(str, uppercase);
	printf("\n%s\n", str);
}*/