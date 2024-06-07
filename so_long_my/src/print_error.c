/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:48:59 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/07 18:02:26 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int type)
{
	ft_printf("Error: ");
	if (type == 1)
		ft_printf("1. The map must be rectangular.\n");
	else if (type == 2)
		ft_printf("2. The map must be surrounded by walls.\n");
	else if (type == 3)
		ft_printf("3. The map must contain only valid characters.\n");
	else if (type == 4)
		ft_printf("4. The map must contain - 1 E, 1 P and some C.\n");
	else if (type == 5)
		ft_printf("5. The map doesn't fit into a screen\n \
				SCREEN_WIDTH: %i, SCREEN_HEIGHT: %i\n", \
				SCREEN_WIDTH, SCREEN_HEIGHT);
	else if (type == 6)
		ft_printf("6. The content of the map is incorrect.\n");
	else if (type == 7)
		ft_printf("7. Wrong map format.\n");
	else if (type == 8)
		ft_printf("8. The map must have a valid path.\n");
	else if (type == 9)
		ft_printf("9. Malloc error.\n");
	else if (type == 10)
		ft_printf("10. Empty [map].ber file.\n");
	else if (type == 11)
		ft_printf("11. Run a program: /so_long [name_of_map].ber.\n");
}
