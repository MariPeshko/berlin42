/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isintmacro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mitadic <mitadic@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:58:43 by mitadic           #+#    #+#             */
/*   Updated: 2024/01/30 14:20:43 by mitadic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isintmacro(const char *c)
{
	if (ft_strncmp(c, "INT_MAX", 7) == 0)
		return (1);
	if (ft_strncmp(c, "INT_MIN", 7) == 0)
		return (-1);
	else
		return (0);
}
