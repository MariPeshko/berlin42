/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:51:33 by mitadic           #+#    #+#             */
/*   Updated: 2023/11/20 15:52:19 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (42);
	else
		return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	unsigned char	c;

	c = 'z';
	printf("is %i alpha? ft_alpha: %i\n", c, ft_isalpha(c));
	printf("is %i alpha? or_alpha: %i\n", c, isalpha(c));
	return (0);
}
*/
