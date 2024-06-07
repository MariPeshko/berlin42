/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 00:02:17 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/07 17:57:24 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_libx(t_mlx *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_printf("Error in max_init function.\n");
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, \
			((data->assets->map_width - 1) * WIDTH), \
			(data->assets->map_height * HEIGHT), "so_long");
	if (data->win == NULL)
	{
		ft_printf("Error in max_new_window function.\n");
		free(data->mlx);
		exit(1);
	}
}
