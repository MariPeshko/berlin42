/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:31:42 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/07 16:34:21 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_open(t_mlx *mlx)
{
	if (mlx->assets->is_door_open == 0)
		return (0);
	return (1);
}

void	door_condition(t_mlx *data)
{
	if (data->assets->coins == 0)
		data->assets->is_door_open = 1;
	else
		return ;
}
