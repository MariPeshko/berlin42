/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:02:29 by mpeshko           #+#    #+#             */
/*   Updated: 2024/06/07 16:26:51 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	determine_player_position(t_relement *game)
{
	int	i;
	int	j;

	i = 0;
	while (++i < game->map_height)
	{
		j = 0;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				if (game->player_pos)
					free(game->player_pos);
				game->player_pos = malloc(sizeof(t_player_pos));
				if (!game->player_pos)
				{
					print_error(9);
					return ;
				}
				game->player_pos->x = j;
				game->player_pos->y = i;
				return ;
			}
		}
	}
}

// Thia function initialize the values with NULL.
// And char **map??
int	ft_init_values(t_mlx *data)
{
	data->assets = malloc(sizeof(t_relement));
	if (!data->assets)
	{
		print_error(9);
		return (0);
	}
	data->assets->moves_count = 1;
	data->assets->coins = 0;
	data->assets->coins_on_path = 0;
	data->assets->map_height = 0;
	data->assets->map_width = 0;
	data->assets->is_door_open = 0;
	data->assets->exit_row = 0;
	data->assets->exit_clm = 0;
	data->assets->player_pos = NULL;
	return (0);
}
